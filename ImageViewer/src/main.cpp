 #include <gtk/gtk.h>

GtkWidget *image;
double last_x = 0;
double last_y = 0;

// ファイルを開くためのダイアログを表示し、選択された画像を表示する
/*
void open_image(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog = gtk_file_chooser_dialog_new("Open Image", NULL, GTK_FILE_CHOOSER_ACTION_OPEN, "Cancel", GTK_RESPONSE_CANCEL, "Open", GTK_RESPONSE_ACCEPT, NULL);
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        gtk_image_set_from_file(GTK_IMAGE(image), filename);
        g_free(filename);
    }
    gtk_widget_destroy(dialog);
}
*/

void open_image(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog = gtk_file_chooser_dialog_new("Open Image", NULL, GTK_FILE_CHOOSER_ACTION_OPEN,
                                                    "Cancel", GTK_RESPONSE_CANCEL,
                                                    "Open", GTK_RESPONSE_ACCEPT, NULL);
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));

        GError *error = NULL;
        GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(filename, &error);
        if (!pixbuf) {
            GtkWidget *error_dialog = gtk_message_dialog_new(NULL,
                    GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "Error loading file: %s", error->message);
            gtk_dialog_run(GTK_DIALOG(error_dialog));
            gtk_widget_destroy(error_dialog);
            g_error_free(error);
        } else {
            gtk_image_set_from_pixbuf(GTK_IMAGE(image), pixbuf);
            g_object_unref(pixbuf);
        }
        g_free(filename);
    }
    gtk_widget_destroy(dialog);
}

// スライダーの値にもどついて画像をズームする
void zoom_image(GtkRange *range, gpointer user_data) {
    double scale = gtk_range_get_value(range);
    GdkPixbuf *pixbuf, *scaled_pixbuf;
    pixbuf = gtk_image_get_pixbuf(GTK_IMAGE(image));
    scaled_pixbuf = gdk_pixbuf_scale_simple(pixbuf, gdk_pixbuf_get_width(pixbuf) * scale, gdk_pixbuf_get_height(pixbuf) * scale, GDK_INTERP_BILINEAR);
    gtk_image_set_from_pixbuf(GTK_IMAGE(image), scaled_pixbuf);
}

// マウスの左ボタンが押されたときにグラブを開始する
gboolean button_pressed(GtkWidget *widget, GdkEventButton *event, gpointer user_data) {
    if (event->button == 1) {
        gtk_widget_grab_focus(widget);
        gtk_grab_add(widget);
        last_x = event->x_root;
        last_y = event->y_root;
    }
    return TRUE;
}

// マウスの左ボタンが離されたときにグラブを終了する
gboolean button_released(GtkWidget *widget, GdkEventButton *event, gpointer user_data) {
    if (event->button == 1) {
        gtk_grab_remove(widget);
    }
    return TRUE;
}

// マウスが移動したときにスクロールウィンドウの調整値を更新する。
gboolean mouse_moved(GtkWidget *widget, GdkEventMotion *event, gpointer user_data) {
    if (gtk_grab_get_current() == widget) {
        GtkAdjustment *adj;
        adj = gtk_scrolled_window_get_hadjustment(GTK_SCROLLED_WINDOW(widget));
        gtk_adjustment_set_value(adj, gtk_adjustment_get_value(adj) + last_x - event->x_root);
        adj = gtk_scrolled_window_get_vadjustment(GTK_SCROLLED_WINDOW(widget));
        gtk_adjustment_set_value(adj, gtk_adjustment_get_value(adj) + last_y - event->y_root);
        last_x = event->x_root;
        last_y = event->y_root;
    }
    return TRUE;
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *menubar;
    GtkWidget *filemenu;
    GtkWidget *file;
    GtkWidget *open;
    GtkWidget *quit;
    GtkWidget *scrolled_win;
    GtkWidget *zoom_slider;

    gtk_init(&argc, &argv); // GTKを初期化する

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL); // 新しいウィンドウを作成する
    gtk_window_set_title(GTK_WINDOW(window), "Image Viewer"); // ウィンドウのタイトルを設定する
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600); // ウィンドウのデフォルトサイズを設定する

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0); // 新しい垂直ボックスを作成する
    gtk_container_add(GTK_CONTAINER(window), vbox); // ウィンドウにボックスを追加する

    menubar = gtk_menu_bar_new(); // 新しいメニューバーを作成する。
    filemenu = gtk_menu_new(); // 新しいメニューを作成する

    file = gtk_menu_item_new_with_label("File"); // 新しいメニューアイテムを作成する
    open = gtk_menu_item_new_with_label("Open"); // 新しいメニューアイテムを作成する
    quit = gtk_menu_item_new_with_label("Quit"); // 新しいメニューアイテムを作成する
 
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), filemenu); // メニューアイテムにサブメニューを設定する
    gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), open); // メニューシェルにメニューアイテムを追加する
    gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), quit); // メニューシェルにメニューアイテムを追加する
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file); // メニューシェルにメニューアイテムを追加する
    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0); // ボックスにメニューバーを追加する

    // ウィンドウが破棄されたときにgtk_main_quitを呼び出すように設定する
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    // メニューアイテムがアクティブになったときにgtk_main_quitを呼び出すように設定する
    g_signal_connect(G_OBJECT(quit), "activate", G_CALLBACK(gtk_main_quit), NULL);
    // メニューアイテムがアクティブになったときにopen_imageを呼び出すように設定する
    g_signal_connect(G_OBJECT(open), "activate", G_CALLBACK(open_image), NULL);


    // 新しいスクロールウィンドウを作成する
    scrolled_win = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_events(scrolled_win, GDK_BUTTON_PRESS_MASK | GDK_POINTER_MOTION_MASK | GDK_BUTTON_RELEASE_MASK);

    // ボックスにスクロールウィンドウを追加する
    gtk_box_pack_start(GTK_BOX(vbox), scrolled_win, TRUE, TRUE, 0);

    // 新しいイメージを作成する
    image = gtk_image_new();
    // イメージウィジェットがマウスのボタン押し下げイベントとポインタの動きイベントを受け取るように設定する
    // gtk_widget_set_events(image, GDK_BUTTON_PRESS_MASK | GDK_POINTER_MOTION_MASK);
    // スクロールウィンドウにイメージを追加する
    gtk_container_add(GTK_CONTAINER(scrolled_win), image);

    // 新しいスライダーを作成する
    // zoom_slider = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0.1, 3.0, 0.1);
    // スライダーの値を設定する
    // gtk_range_set_value(GTK_RANGE(zoom_slider), 1.0);
    // ボックスにスライダーを追加する
    // gtk_box_pack_start(GTK_BOX(vbox), zoom_slider, FALSE, FALSE, 0);

    // g_signal_connect(zoom_slider, "value-changed", G_CALLBACK(zoom_image), NULL);
    g_signal_connect(image, "button-press-event",   G_CALLBACK(button_pressed),  NULL);
    g_signal_connect(image, "button-release-event", G_CALLBACK(button_released), NULL);
    g_signal_connect(image, "motion-notify-event",  G_CALLBACK(mouse_moved),     NULL);

    // ウィンドウとそのすべての子ウィジェットを表示する
    gtk_widget_show_all(window);

    // GTKメインループを開始する
    gtk_main();

    return 0;
}
