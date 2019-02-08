# Use Objs directory since CppUTest cleans that for us. 
main: 
cover: 
	mkdir -p objs
	@lcov --rc lcov_branch_coverage=1 --capture --directory . --output-file objs/coverage.info
report: cover
	@genhtml --branch-coverage objs/coverage.info --output-directory objs
	@xdg-open objs/index.html