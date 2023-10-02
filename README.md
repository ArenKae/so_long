# so long

<p align="center">
  <img src="https://github.com/ArenKae/42-badges/blob/main/so_longe.png" alt="So long 42 project badge"/>
</p>

One of the first graphical projects at 42 school, so_long is a small 2D game where a lost astronaut needs to collect energy cells to power-up his ship. This project uses the school's graphical library, MiniLibX, in order to display a window, handle events, colors and textures.

<p align="center">
  <img src="https://github.com/ArenKae/42-badges/blob/main/screens/so_long.PNG" alt="So_long bonus example by acosi">
</p>

---

## Status
Finished 02/10/2023.

Grade: 125/100

## Usage
To compile, use ```make``` or ```make all```. and launch the program with ```./so_long map/map.ber```

To compile with the bonus part, use ```make bonus``` and launch the program with ```./so_long_bonus map/bonus_map.ber```

### Miscellaneous
- The project was done on Ubuntu Budgie 23.04 and was not tested on MacOS.
- Memory leaks have been thoroughly cheked with Valgrind :
```
valgrind --leak-check=full ./so _long map/map.ber
```
- To make the Minilibx compile on linux, you need to install the following packages :
```
sudo apt-get install xauth xorg openbox libxext-dev libbsd-dev_
```