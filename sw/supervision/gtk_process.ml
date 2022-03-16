(* Automatically generated from /tmp/tmp.f6oEEDv5sC by lablgladecc *)

class hbox_program ?(file="/tmp/tmp.f6oEEDv5sC") ?domain ?autoconnect(*=true*) () =
  let xmldata = Glade.create ~file  ~root:"hbox_program" ?domain () in
  object (self)
    inherit Glade.xml ?autoconnect xmldata
    val toplevel =
      new GPack.box (GtkPack.Box.cast
        (Glade.get_widget_msg ~name:"hbox_program" ~info:"GtkHBox" xmldata))
    method toplevel = toplevel
    val hbox_program =
      new GPack.box (GtkPack.Box.cast
        (Glade.get_widget_msg ~name:"hbox_program" ~info:"GtkHBox" xmldata))
    method hbox_program = hbox_program
    val label_com_name =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_com_name" ~info:"GtkLabel" xmldata))
    method label_com_name = label_com_name
    val entry_program =
      new GEdit.entry (GtkEdit.Entry.cast
        (Glade.get_widget_msg ~name:"entry_program" ~info:"GtkEntry" xmldata))
    method entry_program = entry_program
    val checkbutton_autolaunch =
      new GButton.toggle_button (GtkButton.ToggleButton.cast
        (Glade.get_widget_msg ~name:"checkbutton_autolaunch" ~info:"GtkCheckButton" xmldata))
    method checkbutton_autolaunch = checkbutton_autolaunch
    val button_stop =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_stop" ~info:"GtkButton" xmldata))
    method button_stop = button_stop
    val button_remove =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_remove" ~info:"GtkButton" xmldata))
    method button_remove = button_remove
    method check_widgets () = ()
  end
