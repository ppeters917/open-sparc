#include <windows.h>
#include <stdlib.h>
#include <gtk/gtk.h>

void sparc_login(GtkButton *button, gpointer user_data)
{

}

void sparc_register(GtkButton *button, gpointer user_data)
{
    ShellExecute(NULL, "open", "http://gruntkiller.dlinkddns.com/register", NULL, NULL, SW_SHOWNORMAL);
}

int main (int argc, char *argv[])
{
    GtkWidget *win;
    GtkWidget *vbox;

    GtkWidget *user;
    GtkWidget *passwd;
    GtkWidget *button;
    GtkWidget *reg;

    GtkWidget *user_label;
    GtkWidget *user_text;

    GtkWidget *passwd_label;
    GtkWidget *passwd_text;

    GtkWidget *login_button;
    GtkWidget *quit_button;

    GtkWidget *register_button;

    gtk_init(&argc, &argv);

    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width (GTK_CONTAINER (win), 0);
    gtk_window_set_decorated(GTK_CONTAINER(win), FALSE);
    gtk_window_set_title (GTK_WINDOW (win), "open-sparc");
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_widget_realize (win);
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);

    vbox = gtk_vbox_new (FALSE, 6);

    user = gtk_hbox_new (FALSE, 10);
    passwd = gtk_hbox_new (FALSE, 10);
    button = gtk_hbox_new (TRUE, 10);
    reg = gtk_hbox_new (FALSE, 10);

    user_label = gtk_label_new("User:");
    user_text = gtk_entry_new();

    passwd_label = gtk_label_new("Password:");
    passwd_text = gtk_entry_new();

    login_button = gtk_button_new_with_label("Login");
    quit_button = gtk_button_new_with_label("Quit");

    register_button = gtk_button_new_with_label("Register");

    g_signal_connect(quit_button, "clicked", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(login_button, "clicked", G_CALLBACK(sparc_login), NULL);
    g_signal_connect(register_button, "clicked", G_CALLBACK(sparc_register), NULL);

    gtk_container_add (GTK_CONTAINER (win), vbox);

    gtk_box_pack_start (GTK_BOX (user), user_label, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (user), user_text, FALSE, FALSE, 0);

    gtk_box_pack_start (GTK_BOX (passwd), passwd_label, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (passwd), passwd_text, FALSE, FALSE, 0);

    gtk_box_pack_start (GTK_BOX (button), login_button, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (button), quit_button, TRUE, TRUE, 0);

    gtk_box_pack_start (GTK_BOX (reg), register_button, TRUE, FALSE, 0);

    gtk_box_pack_start (GTK_BOX (vbox), user, FALSE, FALSE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), passwd, FALSE, FALSE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), button, FALSE, FALSE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), reg, FALSE, FALSE, 0);

    gtk_widget_show_all (win);
    gtk_main ();
    return 0;
}
