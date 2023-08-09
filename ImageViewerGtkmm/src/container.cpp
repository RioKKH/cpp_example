#include <gtkmm.h>

int main(int argc, char *argv[])
{
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    Gtk::Window window;
    window.set_default_size(200, 200);

    //- Gtk::Boxはウィジェットを水平または垂直に配置するコンテナ
    //- Gtk::Gridはグリッドレイアウト、Gtk::Notebookはタブ付きページ
    Gtk::Box box(Gtk::ORIENTATION_HORIZONTAL);
    window.add(box);

    Gtk::Button button1("Button 1");
    Gtk::Button button2("Button 2");
    Gtk::Button button3("Button 3");

    // pack_start()メソッドは、ウィジェットをコンテナに追加する
    box.pack_start(button1);
    box.pack_start(button2);
    box.pack_start(button3);

    button1.show();
    button2.show();
    button3.show();
    box.show();

    return app->run(window);
}
