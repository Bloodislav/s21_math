CC 				= gcc
CFLAGS 			= -Wall -Werror -Wextra -Wfloat-equal -Wconversion -std=c11 -pedantic -I.
LDFLAGS 		= -lcheck -lsubunit -lrt -lpthread -lm
DEBUG 			= -g

project_name 	= s21_math
lib_name 		:= $(addsuffix .a, $(project_name))
report_dir		= gcovr-report
func_dir 		= function
test_dir 		= tests
dirs 			:= $(func_dir) $(test_dir)
obj_list 		:= $(patsubst %.c, %.o, $(wildcard $(addsuffix /*.c, $(dirs))))

.PHONY: all clean clean_gcov gcov_report
all: $(lib_name)

test: $(lib_name) $(filter $(test_dir)/%.o, $(obj_list))
	$(CC) -o $@ $(wordlist 2, $(words $^), $^) -L. -l:$< $(LDFLAGS)
	@./$@

$(lib_name): $(filter $(func_dir)/%.o, $(obj_list))
	ar crs $@ $^

gcov_report: GCOVFLAGS = -fprofile-arcs -ftest-coverage
gcov_report: LDFLAGS += -lgcov
gcov_report: clean_gcov test
	@mkdir $(report_dir)
	gcovr --exclude-branches-by-pattern * --html-nested --output $(report_dir)/$(project_name).html

gcov_open:
	xdg-open $(report_dir)/$(project_name).html

%.o: %.c
	$(CC) $(CFLAGS) $(if $(filter $(func_dir)/%.c, $^),$(GCOVFLAGS)) $(DEBUG) -c $^ -o $@

clang-i:
	find . -iname '*.h' -o -iname '*.c' | xargs clang-format -i -style=file:../materials/linters/.clang-format

clang-n:
	find . -iname '*.h' -o -iname '*.c' | xargs clang-format -n -style=file:../materials/linters/.clang-format

clean:
	@rm -rf $(lib_name) test
	@rm -rf $(report_dir)
	@rm -rf $(obj_list) $(addsuffix /*.gcda, $(func_dir)) $(addsuffix /*.gcno, $(func_dir))

clean_gcov:
	@rm -rf $(report_dir) 
	@rm -rf $(filter $(func_dir)/%.o, $(obj_list)) $(addsuffix /*.gcda, $(func_dir)) $(addsuffix /*.gcno, $(func_dir))

.DEFAULT_GOAL := man
man:
	@fgrep -h "##" $(MAKEFILE_LIST) | fgrep -v fgrep | sed -e 's/\\$$//' | sed -e 's/##//'

##
##		Pproject's Makefile manual
##
##Usage: make [TARGET]
##Runs GNU Make with the selected TARGET
##Example: make all
##
##Tasrgets:
##Required targets:
##	all		launches targets s21_math.a
##	clean		clean up the created files 
##	test		testing lib's function	
##	s21_math.a	compiling static lib
##	gcov_report	generate a gcov report 
##			in the form of an html page.
##
##Supporting targets:
##	gcov_open	open a gcov report in the browser
##	clang-n		style check
##
##Report bugs to: ladonnah@student.21-school.ru
##		melonieh@student.21-school.ru
##		roninsha@student.21-school.ru
##Home page: https://repos.21-school.ru/students/C4_s21_math.ID_353528/Team__TL__ladonnah_student.21_school.ru_.TPfnD89zQwqlDy2ZUpx4pg/C4_s21_math-4/-/tree/develop/src
