# C++

## SOLID原則

### 解説

SOLID原則は、オブジェクト指向プログラミングとソフトウェア設計のための5つの基本原則です。これらは、より理解しやすく、メンテナンスしやすく、拡張可能なソフトウェアを作成するのに役立ちます。C++を用いてこれらの原則を説明し、それぞれについて簡単な実装例を示します。

1. **S - Single Responsibility Principle (単一責任の原則)**

   - この原則は、クラスが一つの責任だけを持つべきだと述べています。
   - 例: あるクラスがログ記録とデータ処理の両方を行っている場合、これらは別々のクラスに分けるべきです。

   ```cpp
   class Logger {
   public:
       void log(const std::string &message) {
           // ログ記録のロジック
       }
   };
   
   class DataProcessor {
       Logger logger;
   
   public:
       void process(const std::string &data) {
           // データ処理のロジック
           logger.log("Data processed");
       }
   };
   ```

2. **O - Open/Closed Principle (開放/閉鎖の原則)**

   - ソフトウェアのエンティティは拡張に対して開かれているが、変更に対して閉じているべきです。
   - 例: 新しい機能を追加する場合は、既存のコードを変更するのではなく、新しいクラスや関数を追加することで対応します。

   ```cpp
   class Shape {
   public:
       virtual double area() const = 0;
   };
   
   class Rectangle : public Shape {
       double width, height;
   public:
       Rectangle(double w, double h) : width(w), height(h) {}
       double area() const override { return width * height; }
   };
   
   // 新しい形状を追加する際は、Shapeを拡張するだけで良い
   class Circle : public Shape {
       double radius;
   public:
       Circle(double r) : radius(r) {}
       double area() const override { return 3.14159 * radius * radius; }
   };
   ```

3. **L - Liskov Substitution Principle (リスコフの置換原則)**

   - 派生クラスはその基底クラスに置換可能でなければなりません。
   - 例: 派生クラスは、基底クラスの契約を尊重する必要があります。

   ```cpp
   class Bird {
   public:
       virtual void fly() {
           // 飛行の実装
       }
   };
   
   class Duck : public Bird {
       void fly() override {
           // Duck固有の飛行の実装
       }
   };
   
   class Ostrich : public Bird {
       void fly() override {
           // ダチョウは飛べないので、fly()をオーバーライドしてはいけません。
       }
   };
   ```

4. **I - Interface Segregation Principle (インターフェース分離の原則)**

   - 多くの特定のインターフェースが一つの汎用インターフェースよりも優れています。
   - 例: 一つのインターフェースが多すぎる機能を持っている場合、それをより小さな、特定のインターフェースに分割します。

   ```cpp
   class Printer {
   public:
       virtual void printDocument(const std::string &document) = 0;
   };
   
   class Scanner {
   public:
       virtual void scanDocument(const std::string &document) = 0;
   };
   
   /* このクラスは両方の機能を持ちますが、各機能は独立したインターフェースを通じて実装されています。これにより、印刷機能のみが必要な場合にスキャナーの実装を強制されることはありません。 */
   class MultiFunctionPrinter : public Printer, public Scanner {
   public:
       void printDocument(const std::string &document) override {
           // ドキュメント印刷の実装
       }
   
       void scanDocument(const std::string &document) override {
           // ドキュメントスキャンの実装
       }
   };
   ```

5. **D - Dependency Inversion Principle (依存関係逆転の原則)**

   - 高レベルのモジュールは低レベルのモジュールに依存してはならず、両者は抽象に依存すべきです。
   - 例: モジュール間の直接的な依存関係を避けるために、インターフェースや抽象クラスを使用します。

   ```cpp
   // 抽象インターフェース
   class DataAccessInterface {
   public:
       virtual void readData() = 0;
       virtual void writeData() = 0;
   };
   
   // 具体的な実装
   class FileDataAccess : public DataAccessInterface {
   public:
       void readData() override {
           // ファイルからデータを読み込む
       }
   
       void writeData() override {
           // ファイルにデータを書き込む
       }
   };
   
   // 高レベルモジュール
   class DataManager {
       DataAccessInterface& dataAccess;
   public:
       DataManager(DataAccessInterface& da) : dataAccess(da) {}
   
       void processData() {
           dataAccess.readData();
           // データ処理のロジック
           dataAccess.writeData();
       }
   };
   ```

   このようにして、SOLID原則はソフトウェアの設計をより効果的で、拡張可能で、メンテナンスしやすいものにします。C++の例は原則を示すための簡単なものですが、実際のソフトウェア開発ではこれらの原則をより複雑な方法で適用することが一般的です。