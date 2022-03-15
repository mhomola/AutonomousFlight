Copy the next three files to your paparazzi:

Path to course_conf.xml:  /home/[user_name]/paparazzi/conf/userconf/tudelft/course_conf.xml
- this calls all airframes used during the course
- the airframe with ID 1 is the newly created (i.e. using optical flow stuff)


Path to airframe_conf.xml: /home/[user_name]/paparazzi/conf/airframes/tudelft/bebop_flow_course.xml
- here the simulation and camera are set up
- it calls the optical_flow configuration file

Path to optical flow_conf: /home/[user_name]/paparazzi/conf/modules/cv_opticflow_mav_exercise.xml
- here the optical flow parameters are set up
- CHANGE each path that contains the name \vlad\ with the path of your local GitHub repository (watch out for the TODOs telling you to do the same).

=====================================================================================================================================================


The following files are supposed to stay with your GitHub repo:
 - flow_calcualtor.c/.h
 - opticflow_module.c/.h
 - size_divergence.c/.h






