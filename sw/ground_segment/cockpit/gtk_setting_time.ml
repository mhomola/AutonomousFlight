(* Automatically generated from gcs.glade by lablgladecc *)

class setting_time ?(file="gcs.glade") ?domain ?autoconnect(*=true*) () =
  let xmldata = Glade.create ~file  ~root:"setting_time" ?domain () in
  object (self)
    inherit Glade.xml ?autoconnect xmldata
    val toplevel =
      new GWindow.window (GtkWindow.Window.cast
        (Glade.get_widget_msg ~name:"setting_time" ~info:"GtkWindow" xmldata))
    method toplevel = toplevel
    val setting_time =
      new GWindow.window (GtkWindow.Window.cast
        (Glade.get_widget_msg ~name:"setting_time" ~info:"GtkWindow" xmldata))
    method setting_time = setting_time
    val vbox3 =
      new GPack.box (GtkPack.Box.cast
        (Glade.get_widget_msg ~name:"vbox3" ~info:"GtkVBox" xmldata))
    method vbox3 = vbox3
    val spinbutton_hour =
      new GEdit.spin_button (GtkEdit.SpinButton.cast
        (Glade.get_widget_msg ~name:"spinbutton_hour" ~info:"GtkSpinButton" xmldata))
    method spinbutton_hour = spinbutton_hour
    val spinbutton_min =
      new GEdit.spin_button (GtkEdit.SpinButton.cast
        (Glade.get_widget_msg ~name:"spinbutton_min" ~info:"GtkSpinButton" xmldata))
    method spinbutton_min = spinbutton_min
    val spinbutton_sec =
      new GEdit.spin_button (GtkEdit.SpinButton.cast
        (Glade.get_widget_msg ~name:"spinbutton_sec" ~info:"GtkSpinButton" xmldata))
    method spinbutton_sec = spinbutton_sec
    val button_cancel =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_cancel" ~info:"GtkButton" xmldata))
    method button_cancel = button_cancel
    val button_ok =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_ok" ~info:"GtkButton" xmldata))
    method button_ok = button_ok
    method reparent parent =
      vbox3#misc#reparent parent;
      toplevel#destroy ()
    method check_widgets () = ()
  end
