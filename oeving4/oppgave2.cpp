#include <gtkmm.h>
#include <iostream>

class Window : public Gtk::Window {
public:
  Gtk::Box box;
  Gtk::Entry entry1;
  Gtk::Entry entry2;
  Gtk::Button button;
  Gtk::Label label1;
  Gtk::Label label2;
  Gtk::Label label3;
  bool first_name = false;
  bool last_name = false;

  Window() : box(Gtk::Orientation::ORIENTATION_VERTICAL) {
    set_title("Øving 4");

    label1.set_text("First name");
    label2.set_text("Last name");
    button.set_label("Combine names");

    box.pack_start(label1); // Add the widget label to box
    box.pack_start(entry1); // Add the widget entry to box
    box.pack_start(label2); // Add the widget label to box
    box.pack_start(entry2); // Add the widget entry to box
    box.pack_start(button); // Add the widget button to box
    box.pack_start(label3); // Add the widget label to box

    add(box);   // Add vbox to window
    show_all(); // Show all widgets

    button.set_sensitive(false);

    entry1.signal_changed().connect([this]() {
      if (entry1.get_text_length() > 0) {
        first_name = true;
      } else {
        first_name = false;
      }
      update_button();
    });

    entry2.signal_changed().connect([this]() {
      if (entry2.get_text_length() > 0) {
        last_name = true;
      } else {
        last_name = false;
      }
      update_button();
    });

    button.signal_clicked().connect([this]() {
      label3.set_text("Names combined: " + entry1.get_text() + " " + entry2.get_text());
    });
  }

  void update_button() {
    if (first_name && last_name) {
      button.set_sensitive(true);
    } else {
      button.set_sensitive(false);
    }
  }
};

int main() {
  auto app = Gtk::Application::create();
  Window window;
  return app->run(window);
}
