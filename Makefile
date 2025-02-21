TIMESTAMP := $(shell date +"%Y%m%d_%H%M%S")

all: necessary_compile run_program
	@echo "Command executed = all"


necessary_compile: folder_check run/incongen.exe run/plot.exe run/simulate.exe run/test.exe
	@echo "Command executed = necessary_compile"


folder_check:
	rm -rf run/output
	mkdir -p run/
	mkdir -p run/build
	mkdir -p run/input
	mkdir -p run/output
	mkdir -p run/results-old
	mkdir -p run/output/calculations
	mkdir -p run/output/data-raw
	mkdir -p run/output/graph
	mkdir -p run/output/initial-conditions
	mkdir -p run/output/pressure
	mkdir -p run/output/velocity
	mkdir -p run/output/visualization-nothick
	mkdir -p run/output/visualization-thick
	@echo "Command executed = folder_check"


run_program: folder_check
	./run/simulate.exe
	./run/plot.exe
	zip -r run/results-old/$(TIMESTAMP).zip run/output/


force: clean necessary_compile
	@echo "Command executed = force"


clean:
	rm -rf run/build/


edit:
	geany -i  src/algo/determine.h src/algo/determine.cpp src/algo/utility.h src/algo/utility.cpp src/config_file/head.h src/config_file/incongen.h src/config_file/incongen.cpp src/config_file/simulation.h src/config_file/simulation.cpp src/drw/bmp.h src/drw/bmp.cpp src/dst/head.h src/exe/incongen.cpp src/exe/plot.cpp src/exe/simulate.cpp src/exe/test.cpp src/global/head.h src/incongen/garbage.h src/incongen/garbage.cpp src/incongen/manager.h src/incongen/manager.cpp src/incongen/parameter.h src/incongen/parameter.cpp src/incongen/tlength.h src/incongen/tlength.cpp src/incongen/tmns.h src/incongen/tmns.cpp src/incongen/tradius.h src/incongen/tradius.cpp src/io/cmdprint.h src/io/cmdprint.cpp src/io/cmdread.h src/io/cmdread.cpp src/io/fileplot.h src/io/fileplot.cpp src/io/fileread.h src/io/fileread.cpp src/io/filewrite.h src/io/filewrite.cpp src/math/gausslinear.h src/math/gausslinear.cpp src/math/random.h src/math/random.cpp src/measure/measure.h src/measure/measure.cpp src/network/dimension.h src/network/dimension.cpp src/network/mns.h src/network/mns.cpp src/simulate/manager.h src/simulate/manager.cpp src/smlsteps/01pressure.h src/smlsteps/01pressure.cpp src/smlsteps/02velocity.h src/smlsteps/02velocity.cpp src/smlsteps/03timestep.h src/smlsteps/03timestep.cpp src/smlsteps/04displacement.h src/smlsteps/04displacement.cpp


run/incongen.exe: run/build/exe_incongen.o run/build/algo_determine.o run/build/algo_utility.o run/build/config_file_incongen.o run/build/config_file_simulation.o run/build/drw_bmp.o run/build/incongen_garbage.o run/build/incongen_manager.o run/build/incongen_parameter.o run/build/incongen_tlength.o run/build/incongen_tmns.o run/build/incongen_tradius.o run/build/io_cmdprint.o run/build/io_cmdread.o run/build/io_fileplot.o run/build/io_fileread.o run/build/io_filewrite.o run/build/math_gausslinear.o run/build/math_random.o run/build/measure_measure.o run/build/network_dimension.o run/build/network_mns.o run/build/simulate_manager.o run/build/smlsteps_01pressure.o run/build/smlsteps_02velocity.o run/build/smlsteps_03timestep.o run/build/smlsteps_04displacement.o
	g++  run/build/exe_incongen.o run/build/algo_determine.o run/build/algo_utility.o run/build/config_file_incongen.o run/build/config_file_simulation.o run/build/drw_bmp.o run/build/incongen_garbage.o run/build/incongen_manager.o run/build/incongen_parameter.o run/build/incongen_tlength.o run/build/incongen_tmns.o run/build/incongen_tradius.o run/build/io_cmdprint.o run/build/io_cmdread.o run/build/io_fileplot.o run/build/io_fileread.o run/build/io_filewrite.o run/build/math_gausslinear.o run/build/math_random.o run/build/measure_measure.o run/build/network_dimension.o run/build/network_mns.o run/build/simulate_manager.o run/build/smlsteps_01pressure.o run/build/smlsteps_02velocity.o run/build/smlsteps_03timestep.o run/build/smlsteps_04displacement.o -o run/incongen.exe
	@echo "run/incongen.exe created."


run/plot.exe: run/build/exe_plot.o run/build/algo_determine.o run/build/algo_utility.o run/build/config_file_incongen.o run/build/config_file_simulation.o run/build/drw_bmp.o run/build/incongen_garbage.o run/build/incongen_manager.o run/build/incongen_parameter.o run/build/incongen_tlength.o run/build/incongen_tmns.o run/build/incongen_tradius.o run/build/io_cmdprint.o run/build/io_cmdread.o run/build/io_fileplot.o run/build/io_fileread.o run/build/io_filewrite.o run/build/math_gausslinear.o run/build/math_random.o run/build/measure_measure.o run/build/network_dimension.o run/build/network_mns.o run/build/simulate_manager.o run/build/smlsteps_01pressure.o run/build/smlsteps_02velocity.o run/build/smlsteps_03timestep.o run/build/smlsteps_04displacement.o
	g++  run/build/exe_plot.o run/build/algo_determine.o run/build/algo_utility.o run/build/config_file_incongen.o run/build/config_file_simulation.o run/build/drw_bmp.o run/build/incongen_garbage.o run/build/incongen_manager.o run/build/incongen_parameter.o run/build/incongen_tlength.o run/build/incongen_tmns.o run/build/incongen_tradius.o run/build/io_cmdprint.o run/build/io_cmdread.o run/build/io_fileplot.o run/build/io_fileread.o run/build/io_filewrite.o run/build/math_gausslinear.o run/build/math_random.o run/build/measure_measure.o run/build/network_dimension.o run/build/network_mns.o run/build/simulate_manager.o run/build/smlsteps_01pressure.o run/build/smlsteps_02velocity.o run/build/smlsteps_03timestep.o run/build/smlsteps_04displacement.o -o run/plot.exe
	@echo "run/plot.exe created."


run/simulate.exe: run/build/exe_simulate.o run/build/algo_determine.o run/build/algo_utility.o run/build/config_file_incongen.o run/build/config_file_simulation.o run/build/drw_bmp.o run/build/incongen_garbage.o run/build/incongen_manager.o run/build/incongen_parameter.o run/build/incongen_tlength.o run/build/incongen_tmns.o run/build/incongen_tradius.o run/build/io_cmdprint.o run/build/io_cmdread.o run/build/io_fileplot.o run/build/io_fileread.o run/build/io_filewrite.o run/build/math_gausslinear.o run/build/math_random.o run/build/measure_measure.o run/build/network_dimension.o run/build/network_mns.o run/build/simulate_manager.o run/build/smlsteps_01pressure.o run/build/smlsteps_02velocity.o run/build/smlsteps_03timestep.o run/build/smlsteps_04displacement.o
	g++  run/build/exe_simulate.o run/build/algo_determine.o run/build/algo_utility.o run/build/config_file_incongen.o run/build/config_file_simulation.o run/build/drw_bmp.o run/build/incongen_garbage.o run/build/incongen_manager.o run/build/incongen_parameter.o run/build/incongen_tlength.o run/build/incongen_tmns.o run/build/incongen_tradius.o run/build/io_cmdprint.o run/build/io_cmdread.o run/build/io_fileplot.o run/build/io_fileread.o run/build/io_filewrite.o run/build/math_gausslinear.o run/build/math_random.o run/build/measure_measure.o run/build/network_dimension.o run/build/network_mns.o run/build/simulate_manager.o run/build/smlsteps_01pressure.o run/build/smlsteps_02velocity.o run/build/smlsteps_03timestep.o run/build/smlsteps_04displacement.o -o run/simulate.exe
	@echo "run/simulate.exe created."


run/test.exe: run/build/exe_test.o run/build/algo_determine.o run/build/algo_utility.o run/build/config_file_incongen.o run/build/config_file_simulation.o run/build/drw_bmp.o run/build/incongen_garbage.o run/build/incongen_manager.o run/build/incongen_parameter.o run/build/incongen_tlength.o run/build/incongen_tmns.o run/build/incongen_tradius.o run/build/io_cmdprint.o run/build/io_cmdread.o run/build/io_fileplot.o run/build/io_fileread.o run/build/io_filewrite.o run/build/math_gausslinear.o run/build/math_random.o run/build/measure_measure.o run/build/network_dimension.o run/build/network_mns.o run/build/simulate_manager.o run/build/smlsteps_01pressure.o run/build/smlsteps_02velocity.o run/build/smlsteps_03timestep.o run/build/smlsteps_04displacement.o
	g++  run/build/exe_test.o run/build/algo_determine.o run/build/algo_utility.o run/build/config_file_incongen.o run/build/config_file_simulation.o run/build/drw_bmp.o run/build/incongen_garbage.o run/build/incongen_manager.o run/build/incongen_parameter.o run/build/incongen_tlength.o run/build/incongen_tmns.o run/build/incongen_tradius.o run/build/io_cmdprint.o run/build/io_cmdread.o run/build/io_fileplot.o run/build/io_fileread.o run/build/io_filewrite.o run/build/math_gausslinear.o run/build/math_random.o run/build/measure_measure.o run/build/network_dimension.o run/build/network_mns.o run/build/simulate_manager.o run/build/smlsteps_01pressure.o run/build/smlsteps_02velocity.o run/build/smlsteps_03timestep.o run/build/smlsteps_04displacement.o -o run/test.exe
	@echo "run/test.exe created."


run/build/algo_determine.o: src/algo/determine.h src/algo/determine.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/algo/determine.cpp -o run/build/algo_determine.o
	@echo "run/build/algo_determine.o created."


run/build/algo_utility.o: src/algo/utility.h src/algo/utility.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/algo/utility.cpp -o run/build/algo_utility.o
	@echo "run/build/algo_utility.o created."


run/build/config_file_incongen.o: src/config_file/incongen.h src/config_file/incongen.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/config_file/incongen.cpp -o run/build/config_file_incongen.o
	@echo "run/build/config_file_incongen.o created."


run/build/config_file_simulation.o: src/config_file/simulation.h src/config_file/simulation.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/config_file/simulation.cpp -o run/build/config_file_simulation.o
	@echo "run/build/config_file_simulation.o created."


run/build/drw_bmp.o: src/drw/bmp.h src/drw/bmp.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/drw/bmp.cpp -o run/build/drw_bmp.o
	@echo "run/build/drw_bmp.o created."


run/build/exe_incongen.o: src/exe/incongen.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/exe/incongen.cpp -o run/build/exe_incongen.o
	@echo "run/build/exe_incongen.o created."


run/build/exe_plot.o: src/exe/plot.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/exe/plot.cpp -o run/build/exe_plot.o
	@echo "run/build/exe_plot.o created."


run/build/exe_simulate.o: src/exe/simulate.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/exe/simulate.cpp -o run/build/exe_simulate.o
	@echo "run/build/exe_simulate.o created."


run/build/exe_test.o: src/exe/test.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/exe/test.cpp -o run/build/exe_test.o
	@echo "run/build/exe_test.o created."


run/build/incongen_garbage.o: src/incongen/garbage.h src/incongen/garbage.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/incongen/garbage.cpp -o run/build/incongen_garbage.o
	@echo "run/build/incongen_garbage.o created."


run/build/incongen_manager.o: src/incongen/manager.h src/incongen/manager.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/incongen/manager.cpp -o run/build/incongen_manager.o
	@echo "run/build/incongen_manager.o created."


run/build/incongen_parameter.o: src/incongen/parameter.h src/incongen/parameter.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/incongen/parameter.cpp -o run/build/incongen_parameter.o
	@echo "run/build/incongen_parameter.o created."


run/build/incongen_tlength.o: src/incongen/tlength.h src/incongen/tlength.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/incongen/tlength.cpp -o run/build/incongen_tlength.o
	@echo "run/build/incongen_tlength.o created."


run/build/incongen_tmns.o: src/incongen/tmns.h src/incongen/tmns.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/incongen/tmns.cpp -o run/build/incongen_tmns.o
	@echo "run/build/incongen_tmns.o created."


run/build/incongen_tradius.o: src/incongen/tradius.h src/incongen/tradius.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/incongen/tradius.cpp -o run/build/incongen_tradius.o
	@echo "run/build/incongen_tradius.o created."


run/build/io_cmdprint.o: src/io/cmdprint.h src/io/cmdprint.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/io/cmdprint.cpp -o run/build/io_cmdprint.o
	@echo "run/build/io_cmdprint.o created."


run/build/io_cmdread.o: src/io/cmdread.h src/io/cmdread.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/io/cmdread.cpp -o run/build/io_cmdread.o
	@echo "run/build/io_cmdread.o created."


run/build/io_fileplot.o: src/io/fileplot.h src/io/fileplot.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/io/fileplot.cpp -o run/build/io_fileplot.o
	@echo "run/build/io_fileplot.o created."


run/build/io_fileread.o: src/io/fileread.h src/io/fileread.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/io/fileread.cpp -o run/build/io_fileread.o
	@echo "run/build/io_fileread.o created."


run/build/io_filewrite.o: src/io/filewrite.h src/io/filewrite.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/io/filewrite.cpp -o run/build/io_filewrite.o
	@echo "run/build/io_filewrite.o created."


run/build/math_gausslinear.o: src/math/gausslinear.h src/math/gausslinear.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/math/gausslinear.cpp -o run/build/math_gausslinear.o
	@echo "run/build/math_gausslinear.o created."


run/build/math_random.o: src/math/random.h src/math/random.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/math/random.cpp -o run/build/math_random.o
	@echo "run/build/math_random.o created."


run/build/measure_measure.o: src/measure/measure.h src/measure/measure.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/measure/measure.cpp -o run/build/measure_measure.o
	@echo "run/build/measure_measure.o created."


run/build/network_dimension.o: src/network/dimension.h src/network/dimension.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/network/dimension.cpp -o run/build/network_dimension.o
	@echo "run/build/network_dimension.o created."


run/build/network_mns.o: src/network/mns.h src/network/mns.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/network/mns.cpp -o run/build/network_mns.o
	@echo "run/build/network_mns.o created."


run/build/simulate_manager.o: src/simulate/manager.h src/simulate/manager.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/simulate/manager.cpp -o run/build/simulate_manager.o
	@echo "run/build/simulate_manager.o created."


run/build/smlsteps_01pressure.o: src/smlsteps/01pressure.h src/smlsteps/01pressure.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/smlsteps/01pressure.cpp -o run/build/smlsteps_01pressure.o
	@echo "run/build/smlsteps_01pressure.o created."


run/build/smlsteps_02velocity.o: src/smlsteps/02velocity.h src/smlsteps/02velocity.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/smlsteps/02velocity.cpp -o run/build/smlsteps_02velocity.o
	@echo "run/build/smlsteps_02velocity.o created."


run/build/smlsteps_03timestep.o: src/smlsteps/03timestep.h src/smlsteps/03timestep.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/smlsteps/03timestep.cpp -o run/build/smlsteps_03timestep.o
	@echo "run/build/smlsteps_03timestep.o created."


run/build/smlsteps_04displacement.o: src/smlsteps/04displacement.h src/smlsteps/04displacement.cpp src/config_file/head.h src/dst/head.h src/global/head.h
	g++ -c -Wall -std=c++17 -Isrc/ src/smlsteps/04displacement.cpp -o run/build/smlsteps_04displacement.o
	@echo "run/build/smlsteps_04displacement.o created."
