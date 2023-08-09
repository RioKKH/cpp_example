#include <iostream>
#include <gtkmm.h>

int main(int argc, char *argv[])
{
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    Gtk::Window window;
    window.set_default_size(200, 200);

    // アイコンのファイルパスを指定
    std::string icon_path = "icon.png";

    try {
        Glib::RefPtr<Gdk::Pixbuf> icon = Gdk::Pixbuf::create_from_file(icon_path);
        window.set_icon(icon);
    } catch (const Glib::FileError& ex) {
        std::cerr << "FileError: " << ex.what() << std::endl;
    } catch (const Gdk::PixbufError& ex) {
        std::cerr << "PixbufError: " << ex.what() << std::endl;
    }

    Gtk::Button button("Hello World");
    window.add(button);
    button.show();

    return app->run(window);
}
