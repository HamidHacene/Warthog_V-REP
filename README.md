# Simulation du robot Warthog UGV sous V-REP

Ce projet vise à modéliser le robot Warthog de la société Clearpath Robotics sous V-REP.

[![Warthog UGV demonstration](http://img.youtube.com/vi/ilkuWxcwzV8/0.jpg)](http://www.youtube.com/watch?v=ilkuWxcwzV8)


## Modélisation physique
Nous avons créé une branche spéciale qui contient en plus de la simulation terreste, la partie flottaison du robot. Cette branche est disponible ici : 
[Pafnouti/Warthog_V-REP/tree/buoyancy](https://github.com/Pafnouti/Warthog_V-REP/tree/buoyancy)


## Implémentation ROS
###### Keyboard_teleop

  * Ouvrir un terminal Dans le dossier *ROS* :
  ```bash
    $ rm -rf build/
    $ rm -rf devel/
    $ catkin_make
    $ source devel/setup.bash
    $ rosrun keyboard_transcript kb_t.py
  ```

  * Puis dans un autre terminal : 
  ```bash
    $ rosrun key_teleop key_teleop.py
  ```
  
