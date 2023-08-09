#include <gtkmm.h>

int main(int argc, char *argv[])
{
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    Gtk::Window window;
    window.set_default_size(200, 200);

    Gtk::Button button("Hello World");

    // CSSプロバイダを作成し、CSSを追加します。
    Glib::RefPtr<Gtk::CssProvider> css_provider = Gtk::CssProvider::create();
    // ボタンのラベルの背景色を赤に設定する。
    // --> 実際にはテーマの色に依存してしまうので、このコードでボタンの色を変えることはできない。
    css_provider->load_from_data("label { background-color: red; }");

    // CSSプロバイダをボタンに適用する
    button.get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);

    window.add(button);
    button.show();

    return app->run(window);
}

