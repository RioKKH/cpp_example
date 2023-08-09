#include <gtkmm.h>

int main(int argc, char* argv[])
{
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    Gtk::Window window;
    window.set_default_size(200, 200);

    Gtk::Button button("Hover over me!");
    button.set_tooltip_text("Hello, I'm a tooltip!");

    window.add(button);
    button.show();

    return app->run(window);
}
