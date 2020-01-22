CC = gcc -Werror -Wextra -Wall

NAME = ./MiniRT

libs = -I minirt.h -I types.h -I utils/utils.h -I config/config.h -I geometry/geometry.h  -I libft/libft.h -lmlx -framework openGL -framework AppKit

makeft = make -f libft/Makefile

srcs = config/fill_list.c config/get_next_line.c config/line_parser.c config/reader.c\
geometry/check_intersections.c geometry/check_object.c geometry/clamp_rgb.c\
geometry/get_sphers_normal.c geometry/phong.c geometry/plane_intersect.c\
geometry/ray_init.c geometry/rgb.c geometry/spher_intersect.c geometry/vec_diff.c\
geometry/vec_distance.c geometry/vec_times.c utils/add_object_node.c utils/atod.c\
utils/camera_utils.c utils/clear_object_list.c utils/contains.c utils/create_object_node.c\
utils/create_resolution.c utils/deg_to_rad.c utils/double_abs.c utils/equals.c utils/error.c\
utils/fill_ambient.c utils/fill_camera.c utils/fill_cylinder.c utils/fill_light.c\
utils/fill_plane.c utils/fill_resolution.c utils/fill_rgb.c utils/fill_sphere.c\
utils/fill_square.c utils/fill_triangle.c utils/fill_vec.c utils/free.c\
utils/free_2d.c utils/get_before_last.c utils/get_light_list.c utils/init_resolution.c\
utils/is_in_range.c utils/is_number.c utils/object_props_count.c utils/vec_in_range.c\
check_args.c exit.c init_data.c main.c raytracer.c window.c

all:$(NAME)

$(NAME):
	@$(makeft)
	@$(CC) $(srcs) $(libs) libft.a -o $(NAME)
	@rm -rf libft.a *.o

clean:
	@rm -rf $(NAME)

fclean:clean

re:fclean all