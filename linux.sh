gcc *.c -o minirt utils/*.c config/*.c geometry/*.c libft/*.c -I geometry/geometry.h\
-I utils/utils.h -I libft/*.h -I config/config.h -I\
minirt.h -Itypes.h -lmlx -lX11 -lXext -lm
./minirt scene.rt