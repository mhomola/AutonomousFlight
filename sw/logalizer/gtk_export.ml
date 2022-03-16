(* Automatically generated from /tmp/tmp.RrtbRlm1xk by lablgladecc *)

class export ?(file="/tmp/tmp.RrtbRlm1xk") ?domain ?autoconnect(*=true*) () =
  let xmldata = Glade.create ~file  ~root:"export" ?domain () in
  object (self)
    inherit Glade.xml ?autoconnect xmldata
    val toplevel =
      new GWindow.window (GtkWindow.Window.cast
        (Glade.get_widget_msg ~name:"export" ~info:"GtkWindow" xmldata))
    method toplevel = toplevel
    val export =
      new GWindow.window (GtkWindow.Window.cast
        (Glade.get_widget_msg ~name:"export" ~info:"GtkWindow" xmldata))
    method export = export
    val vbox4 =
      new GPack.box (GtkPack.Box.cast
        (Glade.get_widget_msg ~name:"vbox4" ~info:"GtkVBox" xmldata))
    method vbox4 = vbox4
    val treeview_messages =
      new GTree.view (GtkTree.TreeView.cast
        (Glade.get_widget_msg ~name:"treeview_messages" ~info:"GtkTreeView" xmldata))
    method treeview_messages = treeview_messages
    val box_choose_period =
      new GBin.event_box (GtkBin.EventBox.cast
        (Glade.get_widget_msg ~name:"box_choose_period" ~info:"GtkEventBox" xmldata))
    method box_choose_period = box_choose_period
    val entry_period =
      new GEdit.entry (GtkEdit.Entry.cast
        (Glade.get_widget_msg ~name:"entry_period" ~info:"GtkEntry" xmldata))
    method entry_period = entry_period
    val box_choose_sep =
      new GBin.event_box (GtkBin.EventBox.cast
        (Glade.get_widget_msg ~name:"box_choose_sep" ~info:"GtkEventBox" xmldata))
    method box_choose_sep = box_choose_sep
    val checkbutton_LL =
      new GButton.toggle_button (GtkButton.ToggleButton.cast
        (Glade.get_widget_msg ~name:"checkbutton_LL" ~info:"GtkCheckButton" xmldata))
    method checkbutton_LL = checkbutton_LL
    val button_cancel =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_cancel" ~info:"GtkButton" xmldata))
    method button_cancel = button_cancel
    val button_save =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_save" ~info:"GtkButton" xmldata))
    method button_save = button_save
    method reparent parent =
      vbox4#misc#reparent parent;
      toplevel#destroy ()
    method check_widgets () = ()
  end
