#include <gtk/gtk.h>

void open_image(GtkWidget *widget, gpointer window)
{
    GtkWidget *dialog;
    dialog = gtk_file_chooser_dialog_new(
            "Open File",
            GTK_WINDOW(window),
            GTK_FILE_CHOOSER_ACTION_OPEN,
            ("_Cancel"),
            GTK_RESPONSE_CANCEL,
            ("_Open"),
            GTK_RESPONSE_ACCEPT,
            NULL);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        char *filename;
        filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        // Open the image here.
        g_free(filename);
    }
    gtk_widget_destroy(dialog);
}


int main(int argc, char* argv[])
{
    GtkWidget *window;
    GtkWidget *menubar;
    GtkWidget *fileMenu;
    GtkWidget *fileMi;
    GtkWidget *openMi;
    GtkWidget *vbox;

    gtk_init(&argc, &argv);

    // GTKウィンドウの作成と表示
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // ウィンドウサイズのタイトルとサイズの設定
    gtk_window_set_title(GTK_WINDOW(window), "Image Viewer");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    // メニューバーの作成と配置
    menubar = gtk_menu_bar_new();
    fileMenu = gtk_menu_new();

    fileMi = gtk_menu_item_new_with_label("File");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi), fileMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), fileMi);

    // "開く"オプションの作成
    openMi = gtk_menu_item_new_with_label("Open");
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), openMi);

    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    g_signal_connect(openMi, "activate", G_CALLBACK(open_image), window);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
