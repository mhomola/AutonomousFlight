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
- [ ] Analyze Pyramid Lucas-Kanade algorithm
- [ ] Understand robust estimation (RANSAC part)
- [ ] Get useful details out of OF: FoE, Div, time-to-contact (should be more!)



### **Interface between OF + OD = Vision** :
- [ ] Distance to obstacle from time-to-contact and IMU velocity
- [ ] Nice integration code in C++


### **Interface Vision and Navigation**:
- [ ] Nicer integration code in C++