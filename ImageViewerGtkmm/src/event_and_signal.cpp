#include <gtkmm.h>

/**
 * イベント：キーの押下、マウスのクリックなど、ユーザーの操作によって発生するもの
 * シグナル：イベントが発生すると、関連するウィジェットはシグナルを発行する。
 * シグナルは特定のイベントに対してプログラムが実行するべきアクションを定義する。
 */
class MainWindow : public Gtk::Window
{
public:
    MainWindow()
    {
        m_button.set_label("Click me!");
        //- sigc::mem_fun -> メンバ関数へのポインタをシグナルハンドラとして使用できるように
        //  ラップする関数
        m_button.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_clicked));
        //- add()メソッドは、ウィジェット(この場合はボタン)をコンテナ(この場合はウィンドウ)に
        //  追加するためのメソッド。
        add(m_button);
        m_button.show();
    }

protected:
    void on_button_clicked()
    {
        Gtk::MessageDialog dialog(*this, "Button was clicked!");
        dialog.run();
    }

    Gtk::Button m_button;
};

int main(int argc, char *argv[])
{
    //- Glibオブジェクトの参照カウントを管理するスマートポインタ
    //- ここではGtk::Applicationオブジェクトの参照カウントを管理している
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    MainWindow window;

    return app->run(window);
}
