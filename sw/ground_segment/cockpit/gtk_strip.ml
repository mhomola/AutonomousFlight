(* Automatically generated from gcs.glade by lablgladecc *)

class eventbox_strip ?(file="gcs.glade") ?domain ?autoconnect(*=true*) () =
  let xmldata = Glade.create ~file  ~root:"eventbox_strip" ?domain () in
  object (self)
    inherit Glade.xml ?autoconnect xmldata
    val toplevel =
      new GBin.event_box (GtkBin.EventBox.cast
        (Glade.get_widget_msg ~name:"eventbox_strip" ~info:"GtkEventBox" xmldata))
    method toplevel = toplevel
    val eventbox_strip =
      new GBin.event_box (GtkBin.EventBox.cast
        (Glade.get_widget_msg ~name:"eventbox_strip" ~info:"GtkEventBox" xmldata))
    method eventbox_strip = eventbox_strip
    val frame_strip =
      new GBin.frame (GtkBin.Frame.cast
        (Glade.get_widget_msg ~name:"frame_strip" ~info:"GtkFrame" xmldata))
    method frame_strip = frame_strip
    val vbox_strip =
      new GPack.box (GtkPack.Box.cast
        (Glade.get_widget_msg ~name:"vbox_strip" ~info:"GtkVBox" xmldata))
    method vbox_strip = vbox_strip
    val drawingarea_battery =
      new GMisc.drawing_area (GtkMisc.DrawingArea.cast
        (Glade.get_widget_msg ~name:"drawingarea_battery" ~info:"GtkDrawingArea" xmldata))
    method drawingarea_battery = drawingarea_battery
    val eventbox_mode =
      new GBin.event_box (GtkBin.EventBox.cast
        (Glade.get_widget_msg ~name:"eventbox_mode" ~info:"GtkEventBox" xmldata))
    method eventbox_mode = eventbox_mode
    val label_mode =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_mode" ~info:"GtkLabel" xmldata))
    method label_mode = label_mode
    val eventbox_rc =
      new GBin.event_box (GtkBin.EventBox.cast
        (Glade.get_widget_msg ~name:"eventbox_rc" ~info:"GtkEventBox" xmldata))
    method eventbox_rc = eventbox_rc
    val drawingarea_rc =
      new GMisc.drawing_area (GtkMisc.DrawingArea.cast
        (Glade.get_widget_msg ~name:"drawingarea_rc" ~info:"GtkDrawingArea" xmldata))
    method drawingarea_rc = drawingarea_rc
    val eventbox_gps =
      new GBin.event_box (GtkBin.EventBox.cast
        (Glade.get_widget_msg ~name:"eventbox_gps" ~info:"GtkEventBox" xmldata))
    method eventbox_gps = eventbox_gps
    val label_gps =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_gps" ~info:"GtkLabel" xmldata))
    method label_gps = label_gps
    val drawingarea_agl =
      new GMisc.drawing_area (GtkMisc.DrawingArea.cast
        (Glade.get_widget_msg ~name:"drawingarea_agl" ~info:"GtkDrawingArea" xmldata))
    method drawingarea_agl = drawingarea_agl
    val eventbox_telemetry =
      new GBin.event_box (GtkBin.EventBox.cast
        (Glade.get_widget_msg ~name:"eventbox_telemetry" ~info:"GtkEventBox" xmldata))
    method eventbox_telemetry = eventbox_telemetry
    val label_telemetry =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_telemetry" ~info:"GtkLabel" xmldata))
    method label_telemetry = label_telemetry
    val label_diff_target_alt =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_diff_target_alt" ~info:"GtkLabel" xmldata))
    method label_diff_target_alt = label_diff_target_alt
    val label_altitude =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_altitude" ~info:"GtkLabel" xmldata))
    method label_altitude = label_altitude
    val label_target_altitude =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_target_altitude" ~info:"GtkLabel" xmldata))
    method label_target_altitude = label_target_altitude
    val label_stage_name =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_stage_name" ~info:"GtkLabel" xmldata))
    method label_stage_name = label_stage_name
    val label_block_time =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_block_time" ~info:"GtkLabel" xmldata))
    method label_block_time = label_block_time
    val label_stage_time =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_stage_time" ~info:"GtkLabel" xmldata))
    method label_stage_time = label_stage_time
    val label_eta_time =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_eta_time" ~info:"GtkLabel" xmldata))
    method label_eta_time = label_eta_time
    val eventbox_RDV =
      new GBin.event_box (GtkBin.EventBox.cast
        (Glade.get_widget_msg ~name:"eventbox_RDV" ~info:"GtkEventBox" xmldata))
    method eventbox_RDV = eventbox_RDV
    val label_apt_value =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_apt_value" ~info:"GtkLabel" xmldata))
    method label_apt_value = label_apt_value
    val label_apt =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_apt" ~info:"GtkLabel" xmldata))
    method label_apt = label_apt
    val button_mark =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_mark" ~info:"GtkButton" xmldata))
    method button_mark = button_mark
    val eventbox_flight_time =
      new GBin.event_box (GtkBin.EventBox.cast
        (Glade.get_widget_msg ~name:"eventbox_flight_time" ~info:"GtkEventBox" xmldata))
    method eventbox_flight_time = eventbox_flight_time
    val label_flight_time =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_flight_time" ~info:"GtkLabel" xmldata))
    method label_flight_time = label_flight_time
    val drawingarea_throttle =
      new GMisc.drawing_area (GtkMisc.DrawingArea.cast
        (Glade.get_widget_msg ~name:"drawingarea_throttle" ~info:"GtkDrawingArea" xmldata))
    method drawingarea_throttle = drawingarea_throttle
    val eventbox_speed =
      new GBin.event_box (GtkBin.EventBox.cast
        (Glade.get_widget_msg ~name:"eventbox_speed" ~info:"GtkEventBox" xmldata))
    method eventbox_speed = eventbox_speed
    val drawingarea_speed =
      new GMisc.drawing_area (GtkMisc.DrawingArea.cast
        (Glade.get_widget_msg ~name:"drawingarea_speed" ~info:"GtkDrawingArea" xmldata))
    method drawingarea_speed = drawingarea_speed
    val label_block_name =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_block_name" ~info:"GtkLabel" xmldata))
    method label_block_name = label_block_name
    val frame_nav =
      new GBin.frame (GtkBin.Frame.cast
        (Glade.get_widget_msg ~name:"frame_nav" ~info:"GtkFrame" xmldata))
    method frame_nav = frame_nav
    val alignment_nav =
      new GBin.alignment (GtkBin.Alignment.cast
        (Glade.get_widget_msg ~name:"alignment_nav" ~info:"GtkAlignment" xmldata))
    method alignment_nav = alignment_nav
    val table_nav =
      new GPack.table (GtkPack.Table.cast
        (Glade.get_widget_msg ~name:"table_nav" ~info:"GtkTable" xmldata))
    method table_nav = table_nav
    val button_kill =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_kill" ~info:"GtkButton" xmldata))
    method button_kill = button_kill
    val button_resurrect =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_resurrect" ~info:"GtkButton" xmldata))
    method button_resurrect = button_resurrect
    val button_down =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_down" ~info:"GtkButton" xmldata))
    method button_down = button_down
    val button_up =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_up" ~info:"GtkButton" xmldata))
    method button_up = button_up
    val button_left =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_left" ~info:"GtkButton" xmldata))
    method button_left = button_left
    val button_center =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_center" ~info:"GtkButton" xmldata))
    method button_center = button_center
    val button_right =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_right" ~info:"GtkButton" xmldata))
    method button_right = button_right
    val button_up_up =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_up_up" ~info:"GtkButton" xmldata))
    method button_up_up = button_up_up
    val button_launch =
      new GButton.button (GtkButton.Button.cast
        (Glade.get_widget_msg ~name:"button_launch" ~info:"GtkButton" xmldata))
    method button_launch = button_launch
    val hbox_user =
      new GPack.box (GtkPack.Box.cast
        (Glade.get_widget_msg ~name:"hbox_user" ~info:"GtkHBox" xmldata))
    method hbox_user = hbox_user
    val label_ac_name =
      new GMisc.label (GtkMisc.Label.cast
        (Glade.get_widget_msg ~name:"label_ac_name" ~info:"GtkLabel" xmldata))
    method label_ac_name = label_ac_name
    method reparent parent =
      frame_strip#misc#reparent parent;
      toplevel#destroy ()
    method check_widgets () = ()
  end
