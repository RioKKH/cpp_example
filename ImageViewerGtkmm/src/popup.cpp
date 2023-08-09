#include <gtkmm.h>

class MainWindow : public Gtk::Window
{
public:
    MainWindow()
    {
        set_default_size(200, 200);

        m_button.set_label("Open Popup");
        m_button.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_clicked));

        add(m_button);
        m_button.show();
    }

protected:
    void on_button_clicked()
    {
        Gtk::MessageDialog dialog(*this, "Hello, I'm a popup!");
        dialog.run();
    }

    Gtk::Button m_button;
};

int main(int argc, char *argv[])
{
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    MainWindow window;

    return app->run(window);
}
