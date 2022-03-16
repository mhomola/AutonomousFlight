(* Automatically generated from gcs.glade by lablgladecc *)

class save_settings ?(file="gcs.glade") ?domain ?autoconnect(*=true*) () =
  let xmldata = Glade.create ~file  ~root:"save_settings" ?domain () in
  object (self)
    inherit Glade.xml ?autoconnect xmldata
    val toplevel =
      new GWindow.window (GtkWindow.Window.cast
        (Glade.get_widget_msg ~name:"save_settings" ~info:"GtkWindow" xmldata))
    method toplevel = toplevel
    val save_settings =
      new GWindow.window (GtkWindow.Window.cast
        (Glade.get_widget_msg ~name:"save_settings" ~info:"GtkWindow" xmldata))
    method save_settings = save_settings
    val vbox4 =
      new GPack.box (GtkPack.Box.cast
        (Glade.get_widget_msg ~name:"vbox4" ~info:"GtkVBox" xmldata))
    method vbox4 = vbox4
    val treeview_settings =
      new GTree.view (GtkTree.TreeView.cast
        (Glade.get_widget_msg ~name:"treeview_settings" ~info:"GtkTreeView" xmldata))
    method treeview_settings = treeview_settings
    val button_cancel =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_cancel" ~info:"GtkButton" xmldata))
    method button_cancel = button_cancel
    val button_upload =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_upload" ~info:"GtkButton" xmldata))
    method button_upload = button_upload
    val button_save =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_save" ~info:"GtkButton" xmldata))
    method button_save = button_save
    method reparent parent =
      vbox4#misc#reparent parent;
      toplevel#destroy ()
    method check_widgets () = ()
  end
