(* Automatically generated from /tmp/tmp.N90yPRC0Ou by lablgladecc *)

class window ?(file="/tmp/tmp.N90yPRC0Ou") ?domain ?autoconnect(*=true*) () =
  let xmldata = Glade.create ~file  ~root:"window" ?domain () in
  object (self)
    inherit Glade.xml ?autoconnect xmldata
    val toplevel =
      new GWindow.window (GtkWindow.Window.cast
        (Glade.get_widget_msg ~name:"window" ~info:"GtkWindow" xmldata))
    method toplevel = toplevel
    val window =
      new GWindow.window (GtkWindow.Window.cast
        (Glade.get_widget_msg ~name:"window" ~info:"GtkWindow" xmldata))
    method window = window
    val vbox22 =
      new GPack.box (GtkPack.Box.cast
        (Glade.get_widget_msg ~name:"vbox22" ~info:"GtkVBox" xmldata))
    method vbox22 = vbox22
    val menu =
      new GMenu.menu_shell (GtkMenu.MenuBar.cast
        (Glade.get_widget_msg ~name:"menu" ~info:"GtkMenuBar" xmldata))
    method menu = menu
    val menuitem5_menu =
      new GMenu.menu (GtkMenu.Menu.cast
        (Glade.get_widget_msg ~name:"menuitem5_menu" ~info:"GtkMenu" xmldata))
    method menuitem5_menu = menuitem5_menu
    val menu_item_new_ac =
      new GMenu.image_menu_item (GtkMenu.ImageMenuItem.cast
        (Glade.get_widget_msg ~name:"menu_item_new_ac" ~info:"GtkImageMenuItem" xmldata))
    method menu_item_new_ac = menu_item_new_ac
    val menu_item_copy_ac =
      new GMenu.image_menu_item (GtkMenu.ImageMenuItem.cast
        (Glade.get_widget_msg ~name:"menu_item_copy_ac" ~info:"GtkImageMenuItem" xmldata))
    method menu_item_copy_ac = menu_item_copy_ac
    val delete_ac_menu_item =
      new GMenu.image_menu_item (GtkMenu.ImageMenuItem.cast
        (Glade.get_widget_msg ~name:"delete_ac_menu_item" ~info:"GtkImageMenuItem" xmldata))
    method delete_ac_menu_item = delete_ac_menu_item
    val menu_item_save_ac =
      new GMenu.image_menu_item (GtkMenu.ImageMenuItem.cast
        (Glade.get_widget_msg ~name:"menu_item_save_ac" ~info:"GtkImageMenuItem" xmldata))
    method menu_item_save_ac = menu_item_save_ac
    val menu_item_always_keep_changes =
      new GMenu.check_menu_item (GtkMenu.CheckMenuItem.cast
        (Glade.get_widget_msg ~name:"menu_item_always_keep_changes" ~info:"GtkCheckMenuItem" xmldata))
    method menu_item_always_keep_changes = menu_item_always_keep_changes
    val menu_item_new_target =
      new GMenu.image_menu_item (GtkMenu.ImageMenuItem.cast
        (Glade.get_widget_msg ~name:"menu_item_new_target" ~info:"GtkImageMenuItem" xmldata))
    method menu_item_new_target = menu_item_new_target
    val menu_item_quit =
      new GMenu.image_menu_item (GtkMenu.ImageMenuItem.cast
        (Glade.get_widget_msg ~name:"menu_item_quit" ~info:"GtkImageMenuItem" xmldata))
    method menu_item_quit = menu_item_quit
    val menu_item_session =
      new GMenu.menu_item (GtkMenu.MenuItem.cast
        (Glade.get_widget_msg ~name:"menu_item_session" ~info:"GtkMenuItem" xmldata))
    method menu_item_session = menu_item_session
    val menu_item_session_menu =
      new GMenu.menu (GtkMenu.Menu.cast
        (Glade.get_widget_msg ~name:"menu_item_session_menu" ~info:"GtkMenu" xmldata))
    method menu_item_session_menu = menu_item_session_menu
    val menu_item_new_session =
      new GMenu.image_menu_item (GtkMenu.ImageMenuItem.cast
        (Glade.get_widget_msg ~name:"menu_item_new session" ~info:"GtkImageMenuItem" xmldata))
    method menu_item_new_session = menu_item_new_session
    val menu_item_save_session =
      new GMenu.image_menu_item (GtkMenu.ImageMenuItem.cast
        (Glade.get_widget_msg ~name:"menu_item_save_session" ~info:"GtkImageMenuItem" xmldata))
    method menu_item_save_session = menu_item_save_session
    val menu_item_delete_session =
      new GMenu.image_menu_item (GtkMenu.ImageMenuItem.cast
        (Glade.get_widget_msg ~name:"menu_item_delete_session" ~info:"GtkImageMenuItem" xmldata))
    method menu_item_delete_session = menu_item_delete_session
    val programs_menu_item =
      new GMenu.menu_item (GtkMenu.MenuItem.cast
        (Glade.get_widget_msg ~name:"programs_menu_item" ~info:"GtkMenuItem" xmldata))
    method programs_menu_item = programs_menu_item
    val view1_menu =
      new GMenu.menu (GtkMenu.Menu.cast
        (Glade.get_widget_msg ~name:"view1_menu" ~info:"GtkMenu" xmldata))
    method view1_menu = view1_menu
    val menu_item_fullscreen =
      new GMenu.image_menu_item (GtkMenu.ImageMenuItem.cast
        (Glade.get_widget_msg ~name:"menu_item_fullscreen" ~info:"GtkImageMenuItem" xmldata))
    method menu_item_fullscreen = menu_item_fullscreen
    val menuitem8_menu =
      new GMenu.menu (GtkMenu.Menu.cast
        (Glade.get_widget_msg ~name:"menuitem8_menu" ~info:"GtkMenu" xmldata))
    method menuitem8_menu = menuitem8_menu
    val menu_item_about =
      new GMenu.menu_item (GtkMenu.MenuItem.cast
        (Glade.get_widget_msg ~name:"menu_item_about" ~info:"GtkMenuItem" xmldata))
    method menu_item_about = menu_item_about
    val menu_item_get_help =
      new GMenu.menu_item (GtkMenu.MenuItem.cast
        (Glade.get_widget_msg ~name:"menu_item_get_help" ~info:"GtkMenuItem" xmldata))
    method menu_item_get_help = menu_item_get_help
    val menu_item_version =
      new GMenu.menu_item (GtkMenu.MenuItem.cast
        (Glade.get_widget_msg ~name:"menu_item_version" ~info:"GtkMenuItem" xmldata))
    method menu_item_version = menu_item_version
    val hpaned =
      new GPack.paned (GtkPack.Paned.cast
        (Glade.get_widget_msg ~name:"hpaned" ~info:"GtkHPaned" xmldata))
    method hpaned = hpaned
    val vbox_left_pane =
      new GPack.box (GtkPack.Box.cast
        (Glade.get_widget_msg ~name:"vbox_left_pane" ~info:"GtkVBox" xmldata))
    method vbox_left_pane = vbox_left_pane
    val hbox_ac =
      new GPack.box (GtkPack.Box.cast
        (Glade.get_widget_msg ~name:"hbox_ac" ~info:"GtkHBox" xmldata))
    method hbox_ac = hbox_ac
    val vbox_ac =
      new GPack.box (GtkPack.Box.cast
        (Glade.get_widget_msg ~name:"vbox_ac" ~info:"GtkVBox" xmldata))
    method vbox_ac = vbox_ac
    val button_refresh =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_refresh" ~info:"GtkButton" xmldata))
    method button_refresh = button_refresh
    val entry_ac_id =
      new GEdit.entry (GtkEdit.Entry.cast
        (Glade.get_widget_msg ~name:"entry_ac_id" ~info:"GtkEntry" xmldata))
    method entry_ac_id = entry_ac_id
    val eventbox_gui_color =
      new GBin.event_box (GtkBin.EventBox.cast
        (Glade.get_widget_msg ~name:"eventbox_gui_color" ~info:"GtkEventBox" xmldata))
    method eventbox_gui_color = eventbox_gui_color
    val button_gui_color =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_gui_color" ~info:"GtkButton" xmldata))
    method button_gui_color = button_gui_color
    val label_airframe =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_airframe" ~info:"GtkLabel" xmldata))
    method label_airframe = label_airframe
    val button_browse_airframe =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_browse_airframe" ~info:"GtkButton" xmldata))
    method button_browse_airframe = button_browse_airframe
    val button_edit_airframe =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_edit_airframe" ~info:"GtkButton" xmldata))
    method button_edit_airframe = button_edit_airframe
    val label_flight_plan =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_flight_plan" ~info:"GtkLabel" xmldata))
    method label_flight_plan = label_flight_plan
    val button_browse_flight_plan =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_browse_flight_plan" ~info:"GtkButton" xmldata))
    method button_browse_flight_plan = button_browse_flight_plan
    val button_edit_flight_plan =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_edit_flight_plan" ~info:"GtkButton" xmldata))
    method button_edit_flight_plan = button_edit_flight_plan
    val tree_settings =
      new GTree.view (GtkTree.TreeView.cast
        (Glade.get_widget_msg ~name:"tree_settings" ~info:"GtkTreeView" xmldata))
    method tree_settings = tree_settings
    val button_browse_settings =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_browse_settings" ~info:"GtkButton" xmldata))
    method button_browse_settings = button_browse_settings
    val button_edit_settings =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_edit_settings" ~info:"GtkButton" xmldata))
    method button_edit_settings = button_edit_settings
    val button_remove_settings =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_remove_settings" ~info:"GtkButton" xmldata))
    method button_remove_settings = button_remove_settings
    val tree_settings_modules =
      new GTree.view (GtkTree.TreeView.cast
        (Glade.get_widget_msg ~name:"tree_settings_modules" ~info:"GtkTreeView" xmldata))
    method tree_settings_modules = tree_settings_modules
    val label_radio =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_radio" ~info:"GtkLabel" xmldata))
    method label_radio = label_radio
    val button_browse_radio =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_browse_radio" ~info:"GtkButton" xmldata))
    method button_browse_radio = button_browse_radio
    val button_edit_radio =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_edit_radio" ~info:"GtkButton" xmldata))
    method button_edit_radio = button_edit_radio
    val label_telemetry =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_telemetry" ~info:"GtkLabel" xmldata))
    method label_telemetry = label_telemetry
    val button_browse_telemetry =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_browse_telemetry" ~info:"GtkButton" xmldata))
    method button_browse_telemetry = button_browse_telemetry
    val button_edit_telemetry =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_edit_telemetry" ~info:"GtkButton" xmldata))
    method button_edit_telemetry = button_edit_telemetry
    val label_release =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_release" ~info:"GtkLabel" xmldata))
    method label_release = label_release
    val button_compare_release =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_compare_release" ~info:"GtkButton" xmldata))
    method button_compare_release = button_compare_release
    val button_gitk =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_gitk" ~info:"GtkButton" xmldata))
    method button_gitk = button_gitk
    val button_store_release =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_store_release" ~info:"GtkButton" xmldata))
    method button_store_release = button_store_release
    val vbox_target =
      new GPack.box (GtkPack.Box.cast
        (Glade.get_widget_msg ~name:"vbox_target" ~info:"GtkVBox" xmldata))
    method vbox_target = vbox_target
    val vbox_flash =
      new GPack.box (GtkPack.Box.cast
        (Glade.get_widget_msg ~name:"vbox_flash" ~info:"GtkVBox" xmldata))
    method vbox_flash = vbox_flash
    val button_clean =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_clean" ~info:"GtkButton" xmldata))
    method button_clean = button_clean
    val button_build =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_build" ~info:"GtkButton" xmldata))
    method button_build = button_build
    val button_upload =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_upload" ~info:"GtkButton" xmldata))
    method button_upload = button_upload
    val checkbutton_printconfig =
      new GButton.toggle_button (GtkButton.ToggleButton.cast
        (Glade.get_widget_msg ~name:"checkbutton_printconfig" ~info:"GtkCheckButton" xmldata))
    method checkbutton_printconfig = checkbutton_printconfig
    val session =
      new GBin.frame (GtkBin.Frame.cast
        (Glade.get_widget_msg ~name:"Session" ~info:"GtkFrame" xmldata))
    method session = session
    val vbox_session =
      new GPack.box (GtkPack.Box.cast
        (Glade.get_widget_msg ~name:"vbox_session" ~info:"GtkVBox" xmldata))
    method vbox_session = vbox_session
    val button_execute =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_execute" ~info:"GtkButton" xmldata))
    method button_execute = button_execute
    val button_remove_all_processes =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_remove_all_processes" ~info:"GtkButton" xmldata))
    method button_remove_all_processes = button_remove_all_processes
    val vbox_programs =
      new GPack.box (GtkPack.Box.cast
        (Glade.get_widget_msg ~name:"vbox_programs" ~info:"GtkVBox" xmldata))
    method vbox_programs = vbox_programs
    val console =
      new GText.view (GtkText.View.cast
        (Glade.get_widget_msg ~name:"console" ~info:"GtkTextView" xmldata))
    method console = console
    val statusbar =
      new GMisc.statusbar (GtkMisc.Statusbar.cast
        (Glade.get_widget_msg ~name:"statusbar" ~info:"GtkStatusbar" xmldata))
    method statusbar = statusbar
    method reparent parent =
      vbox22#misc#reparent parent;
      toplevel#destroy ()
    method check_widgets () = ()
  end
