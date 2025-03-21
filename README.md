# So_long

<p align="center">
  <img src="https://github.com/ArenKae/ArenKae/blob/main/42%20badges/so_longe.png" alt="So long 42 project badge"/>
</p>

One of the first graphical projects at 42 school, so_long is a small 2D game where a lost astronaut needs to collect energy cells to power up his ship. This project uses the school's graphical library, [MiniLibX](https://github.com/42Paris/minilibx-linux), in order to display a window, handle events, colors and textures.


<p align="center">
  <img src="https://github.com/ArenKae/ArenKae/blob/main/screens/so_long.gif" alt="So_long demo screenshot">
</p>

---

## Status
✅ Completed on: 02/10/2023
</br>
🏆 Grade: 125/100

## Usage
- First, install the following dependencies to allow the Minilibx to compile :
```
sudo apt install xauth xorg openbox libxext-dev libbsd-dev
```
- To compile, use ```make``` or ```make all```. and launch the program with :
```
./so_long map/map.ber
```

- To compile with the bonus part, use ```make bonus``` and launch the program with 
```
./so_long_bonus map/bonus_map.ber
```

> [!NOTE]
> You can use either WASD or ZQSD to move the player on the map.

### 💻 This project was developed on Ubuntu 23.04.
