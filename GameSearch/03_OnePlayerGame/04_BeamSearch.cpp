// ゲームで学ぶ探索アルゴリズム実践入門
// コード写経

#include <string>
#include <sstream>
#include <random>
#include <iostream>
#include <cassert>
#include <queue>

// 座標を保持する構造体
struct Coord
{
public:
    int y_;
    int x_;
    Coord(const int y = 0, const int x = 0) : y_(y), x_(x) {}
};

std::mt19937 mt_for_action(0); // 行動洗濯用の乱数生成器を初期化する
using ScoreType = int64_t;     // ゲームの評価スコアの型を決めておく
constexpr const ScoreType INF = 1000000000LL; // あり得ないぐらい大きなスコアの例を用意しておく

// constexpr は汎用的に定数式を表現するための機能
// この機能を使用することで、コンパイル時に値が決定する定数、
// コンパイル時に実行される関数、コンパイル時にリテラルとして
// ふるまうクラスを定義できる
constexpr const int H = 3;  // 迷路の高さ
constexpr const int W = 4;  // 迷路の幅
constexpr int END_TURN = 4; // ゲーム終了ターン

/**
 * 一人ゲームの例
 * 1ターンに上下左右四方向のいずれかに１マスずつ進む。
 * 床にあるポイントを踏むと自身のスコアとなり、床のポイントが消える。
 * END_TURNの時点のスコアを高くすることが目的
 */

class MazeState
{
private:
    // static constexprはクラスのインスタンス化とは無関係に、コンパイル時に
    // 解決される定数式として扱われる。 staticメンバ変数は各インスタンスではなく、
    // クラス自体に属する。従って各インスタンス毎に同じ値を持つ必要がある場合には、
    // メモリの節約となる
    // constexprメンバ変数はコンパイル時に解決される為、実行時エラーを防止できる
    // また、定数式として扱われる為、意図しない変更を防ぐことが出来る
    // static constexprメンバ変数は、コンパイル時に解決される定数式として扱われる為、
    // プログラムの実行前に値が計算される。これにより初期化のための実行時のオーバーヘッドを
    // 避けることが出来る。また、定数式として扱われる為、関数の引数として使用できる
    // クラスにstatic constexpr修飾子を付けた配列メンバを宣言のみで利用するさいには
    // C++17以上である必要がある
    static constexpr const int dx[4] = {1, -1, 0,  0}; // 右、左、下、上への移動方向のX成分
    static constexpr const int dy[4] = {0,  0, 1, -1}; // 右、左、下、上への移動方向のY成分

    int points_[H][W] = {}; // 床のポイントを1~9で表現する
    int turn_ = 0;          // 現在のターン

public:
    Coord character_ = Coord();
    int game_score_ = 0;            // ゲーム上で実際に得たスコア
    ScoreType evaluated_score_ = 0; // 探索上で評価したスコア
    int first_action_ = -1;         // 探索木のルートノードで最初に選択した行動
    MazeState() {}

    // h*w の迷路を生成する。
    MazeState(const int seed)
    {
        auto mt_for_construct = std::mt19937(seed); // 盤面構築用の疑似乱数生成器をseedを用いて初期化する
        this->character_.y_ = mt_for_construct() % H;
        this->character_.x_ = mt_for_construct() % W;

        for (int y = 0; y < H; y++)
        {
            for (int x = 0; x < W; x++)
            {
                if (y == character_.y_ && x == character_.x_)
                {
                    continue;
                }
                this->points_[y][x] = mt_for_construct() % 10;
            }
        }
    }

    // [どのゲームでも実装する]: ゲームの終了判定
    bool isDone() const
    {
        return this->turn_ == END_TURN;
    }

    // [どのゲームでも実装する]: 探索用の盤面評価をする
    void evaluateScore()
    {
        this->evaluated_score_ = this->game_score_; // 簡単の為、まずはゲームスコアをそのまま盤面の評価とする
        this->evaluated_score_ = this->game_score_; // 簡単の為、まずはゲームスコアをそのまま盤面の評価とする
    }

    // [どのゲームでも実装する]: 指定したactionでゲームを1ターン進める
    void advance(const int action)
    {
        this->character_.x_ += dx[action];
        this->character_.y_ += dy[action];
        // pointで床に配置された点数を参照している(別名を付けていることに相当する)
        auto &point = this->points_[this->character_.y_][this->character_.x_];
        if (point > 0)
        {
            this->game_score_ += point;
            // 従って、ここでpoint=0と更新すると、this-points_にも反映される
            // 参照を使わない場合には以下のような記述となる
            // this->points_[this->character_.y_][this->character_.x_] = 0
            point = 0;
        }
        this->turn_++;
    }

    // [どのゲームでも実装する]: 現在の状況でプレイヤーが可能な行動をすべて取得する
    // 上下左右の4方向にキャラクターが移動できるかを判定し、合法手として追加する。
    std::vector<int> legalActions() const
    {
        std::vector<int> actions;
        for (int action = 0; action < 4; action++)
        {
            int ty = this->character_.y_ + dy[action];
            int tx = this->character_.x_ + dx[action];
            // 盤外に移動しようとしていないかを確認する
            if (ty >= 0 && ty < H && tx >= 0 && tx < W)
            {
                // emplace_backはコピーが不要で、コンストラクタ引数を直接渡すことが
                // 出来る場合に使用される。
                actions.emplace_back(action); // <--合法手を追加する
            }
        }
        return actions;
    }


    // [実装しなくてもよいが実装すると便利]: 現在のゲーム状況を文字列にする
    std::string toString() const
    {
        std::stringstream ss;
        ss << "trun:\t" << this->turn_ << "\n";
        ss << "score:\t" << this->game_score_ << "\n";
        for (int h = 0; h < H; h++)
        {
            for (int w = 0; w < W; w++)
            {
                if (this->character_.y_ == h && this->character_.x_ == w)
                {
                    ss << '@'; // キャラクター
                }
                else if (this->points_[h][w] > 0)
                {
                    ss << points_[h][w]; // 床にあるポイント
                }
                else
                {
                    ss << '.'; // 床
                }
            }
            ss << '\n';

        }
        return ss.str();
    }
}; // End of class definitions

// [どのゲームでも実装する]: 探索時のソート用に評価を比較する
// 探索時にノードをソートするために比較演算子を実装する
bool operator<(const MazeState &maze_1, const MazeState &maze_2)
{
    return maze_1.evaluated_score_ < maze_2.evaluated_score_;
}

using State = MazeState;

// ビーム幅と深さを指定してビームサーチで行動を決定する
// ビームサーチとは探索アルゴリズムの一種で、探索空間内で最適解を見つける
// ために使用される。ビームサーチでは各探索ステップで複数の解候補を同時に
// 保持し、最も有望な解候補のみを選択することによって、効率的に最適解を
// 見つけることが出来る。
// ビームとは、探索ステップごとに選択される解候補の集合の事を指す。
// ビームサーチでは最も有望な解候補のみを選択するために、ビームサイズを
// 制限する。つまり各ステップで最も有望な解候補の数をあらかじめ決定し、
// それ以外の解候補を破棄する。
int beamSearchAction(const State &state, const int beam_width, const int beam_depth)
{
    // std::priority_queueは優先順位付きキューを実現するコンテナアダプタである。
    // 要素をpush()で追加し、top()で取り出す。Compare述語で優先順に要素が取り出される
    // デフォルトでは降順比較のlessが使用される
    std::priority_queue<State> now_beam;
    State best_state;

    now_beam.push(state);
    // ビーム深さはここでは何ターン先まで探索するかに相当する
    for (int t = 0; t < beam_depth; t++)
    {
        std::priority_queue<State> next_beam;
        // ビーム幅分だけ解候補を探索する
        for (int i = 0; i < beam_width; i++)
        {
            if (now_beam.empty())
            {
                break;
            }

            // top(): 次の要素にアクセスする
            State now_state = now_beam.top();
            // pop(): 次の要素を削除する
            now_beam.pop();
            auto legal_actions = now_state.legalActions();
            for (const auto &action : legal_actions)
            {
                State next_state = now_state;
                next_state.advance(action);
                next_state.evaluateScore();
                if (t == 0)
                {
                    next_state.first_action_ = action;
                }
                next_beam.push(next_state);
            }
        }

        now_beam = next_beam;
        // 探索が終わったタイミングで最も評価が高かった盤面を選べばよい
        // top()を使えば最も評価の高い状態を取得できる
        best_state = now_beam.top();

        if (best_state.isDone())
        {
            break;
        }
    }
    return best_state.first_action_;
}




// MazeStateでも実装できるが、各アルゴリズムを数字集めゲーム以外にも適用して
// 実装することをいしきして、Stateというエイリアスを割り当てた。


// ランダムに行動を決定する
int randomAction(const State &state)
{
    // 合法手の中からランダムに1つ行動を選択する
    auto legal_actions = state.legalActions();
    return legal_actions[mt_for_action() % (legal_actions.size())];
}


// 貪欲法で行動を決定する
int greedyAction(const State &state)
{
    auto legal_actions = state.legalActions();
    ScoreType best_score = -INF; // 絶対にありえない小さな値でベストスコアを初期化する
    int best_action = -1; // あり得ない行動で初期化する
    for (const auto action : legal_actions)
    {
        State now_state = state;
        now_state.advance(action);
        now_state.evaluateScore();
        if (now_state.evaluated_score_ > best_score)
        {
            best_score = now_state.evaluated_score_;
            best_action = action;
        }
    }
    // 不安ならここにassertを入れてチェックしてもよい
    assert(best_action != -1);
    return best_action;
}


// ゲームをgame_number回プレイして平均スコアを表示する
void testAiScore(const int game_number)
{
    using std::cout;
    using std::endl;
    std::mt19937 mt_for_construct(0);
    double score_mean = 0;
    for (int i = 0; i < game_number; i++)
    {
        auto state = State(mt_for_construct());

        while (!state.isDone())
        {
            state.advance(beamSearchAction(state, /*beam幅*/ 2,/*beam深さ*/ END_TURN));
            // state.advance(greedyAction(state));
        }
        auto score = state.game_score_;
        score_mean += score;
    }
    score_mean /= (double)game_number;
    cout << "Score:\t" << score_mean << endl;
}


int main()
{
    testAiScore(/*ゲームを繰り返す回数*/ 100);
    return 0;
}
