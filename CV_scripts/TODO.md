# Progress & TODOs:

I have put together some steps for the Vision part of our project. 
Most of the ideas are just what I was quickly 'sketching' in my had. They are by no means a result of some careful literature survey or intense YouTube watching. 


*Please* be critical w.r.t the ideas below.

### **Obstacle detection (OD)**:
I would say this has *high priority* since should really work well.
- [ ] Implement simple obstacle_detector() method
- [ ] Design tests for its accuracy (ROC curves are here??)
  
### **Optical Flow (OF)**:
Maybe more complex but definitely useful for when the OD works. 
- [x] Run notebooks from BS
- [x] Pre-process useful drone-camera data from BS
- [x] Determine Optical Flow on real drone-camera images (front camera used)
- [x] Analyze Pyramid Lucas-Kanade algorithm
- [ ] [Understand robust estimation (RANSAC part)] - Not very relevant
- [x] Get useful details out of OF: FoE, Div, time-to-contact (TTC)
  
  For more robust TTC: https://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.49.7076 (if it worked in 1995, maybe it is simple enough for our MAV)

  - [x] Interpolate navigation state data
  - [ ] Subtract the rotational motion available from drone state data
   



### **Interface between OF + OD = Vision** :
- [ ] Distance to obstacle from time-to-contact and IMU velocity
- [x] Check interestingly simple half-plane control law from: https://journals.sagepub.com/doi/full/10.5772/5715 (just Equation 4 is enough!!)
- [ ] Nice integration code in C/C++


### **Interface Vision and Navigation**:
- [ ] Nicer integration code in C/C++