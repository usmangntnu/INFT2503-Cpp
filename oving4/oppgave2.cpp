#include <gtkmm/application.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>
#include <gtkmm/window.h>

class NameWindow : public Gtk::Window {
public:
  Gtk::Box box;
  Gtk::Entry entry_first;
  Gtk::Entry entry_last;
  Gtk::Button button;
  Gtk::Label label;

  NameWindow() : box(Gtk::ORIENTATION_VERTICAL) {
    // Sett vindustittel
    set_title("Navnesammenslåer");

    // Sett plassholdere for tekstfeltene
    entry_first.set_placeholder_text("Skriv inn fornavn");
    entry_last.set_placeholder_text("Skriv inn etternavn");

    // Sett knappetekst
    button.set_label("Slå sammen navn");
    button.set_sensitive(false); // starter som grået ut

    // Legg til widgets i layout-boksen
    box.set_spacing(5);
    box.pack_start(entry_first);
    box.pack_start(entry_last);
    box.pack_start(button);
    box.pack_start(label);

    // Legg boksen i vinduet og vis alt
    add(box);
    show_all_children();

    // Signaler: Når tekst endres → sjekk om begge feltene har innhold
    entry_first.signal_changed().connect(sigc::mem_fun(*this, &NameWindow::update_button_state));
    entry_last.signal_changed().connect(sigc::mem_fun(*this, &NameWindow::update_button_state));

    // Når knappen trykkes → oppdater label
    button.signal_clicked().connect([this]() {
      label.set_text(entry_first.get_text() + " " + entry_last.get_text());
    });
  }

private:
  void update_button_state() {
    bool has_first = !entry_first.get_text().empty();
    bool has_last = !entry_last.get_text().empty();
    button.set_sensitive(has_first && has_last);
  }
};

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
  NameWindow window;
  return app->run(window);
}
