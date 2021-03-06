# SYMPHONY Version 5.6 README

Welcome to SYMPHONY. SYMPHONY is distributed under the Eclipse Public License
and is freely redistributable. All source code and documentation is Copyright
2000-2019 by Ted Ralphs and others. This README may be redistributed freely.

# CURRENT BUILD STATUS

[![Build Status](https://travis-ci.org/coin-or/SYMPHONY.svg?branch=master)](https://travis-ci.org/coin-or/SYMPHONY)

[![Build status](https://ci.appveyor.com/api/projects/status/220ltxwv2w2ac51s/branch/master?svg=true)](https://ci.appveyor.com/project/tkralphs/symphony/branch/master)

## CITE

[![DOI](https://zenodo.org/badge/23689820.svg)](https://zenodo.org/badge/latestdoi/23689820)

## DOWNLOAD

[ ![Download](https://api.bintray.com/packages/coin-or/download/SYMPHONY/images/download.svg?version=5.6) ](https://bintray.com/coin-or/download/SYMPHONY/5.6)

Binaries for most platforms are available for download from [Bintray](https://bintray.com/coin-or/download/SYMPHONY). Binaries can also be installed on specific platforms, as follows. 

 * *Linux*: On Debian, SYMPHONY is available in the package `coinor-symphony` and can be installed with apt. On Fedora, SYMPHONY is available in the package `coin-or-SYMPHONY`. Pre-compiled binaries are also available on [BinTray](http://bintray.com/coin-or/download/SYMPHONY) and as part of the [COIN-OR Optimization Suite](https://www.coin-or.org/download/binary/OptimizationSuite/).
 * *Windows*: The easiest way to get SYMPHONY on Windows is to download binaries from [BinTray](http://bintray.com/coin-or/download/SYMPHONY) or just use the Windows installer for the [COIN Optimization Suite](http://www.coin-or.org/download/binary/OptimizationSuite), which provides Visual Studio compatible libraries and binaries (these are slightly out of date, however). 
 * *OS X*: The easiest way to get SYMPHONY on OSX is through Homebrew. It can be installed with
   * `brew tap coin-or-tools/coinor`
   * `brew install symphony`.

Due to license incompatibilities, pre-compiled binaries lack some functionality and are not available for the distributed parallel version of SYMPHONY. If binaries are not available for your platform for the latest version and you would like to request them to be built and posted, feel free to let us know on the mailing list or by opening an [issue](https://github.com/coin-or/SYMPHONY/newissue).

# DOCUMENTATION

If you have downloaded a source distribution, LaTex source for the full documentation is available in the SYMPHONY/Doc/ subdirectory. Quick start guides and pointers to other on-line documentation can be found at the project Wiki:

https://github.com/coin-or/SYMPHONY/wiki

The on-line version of the manual is available here:

http://coin-or.github.io/SYMPHONY/man-5.6/

What follows is a very brief summary of
installation and usage. Please see the documentation for more details.

## BUILDING FROM SOURCE

If you downloaded a source distribution and would like instructions on
building SYMPHONY or you downloaded a binary distribution and would like to
know how to install it, please see the [INSTALL](https://github.com/coin-or/SYMPHONY/blob/master/INSTALL.md) file.

## USING SYMPHONY

### Using SYMPHONY from the command line

To use SYMPHONY as a generic solver, type the executable name on the command
line, followed by one or more of the command-line switches. On the
command-line, there is one required switch---you must specify the location of
the input file by using either "-F 'filename'" (MPS file or automatic
detection with file extension) or "-L 'filename'" (LP format). If the "-D"
switch is also present, the file will be assumed to be a GMPL model file with
the data file specified after the "-D" switch. In LINUX, the following command
would solve the instance "sample.mps"

```symphony -F sample.mps```

The remaining switches are used to set SYMPHONY's native parameters on the
command line. Below is a list of these parameters. This list can also be
obtained by executng 

```symphony -h```

Note that all SYMPHONY parameters are denoted by a lowercase letter. Many
other parameters can be set with the use of a parameter file (specified with
-f). These parameters are listed in the SYMPHONY user's manual.

```
symphony [ -FL file ] [ -f parameter_file_name ]
        [ -hd ] [-a 0/1] [-b 0/1 ] [-s cands] [-l 0/1] [ -q 0/1 ] [ -r 0/1]
        [-j 0/1 ] [ -e n ] [ -i iters ] [ -t time ] [ -g gap ] [ -n nodes ]
        [ -u ub ] [ -p procs ] [ -k rule ] [ -v level ] [ -c rule ]
        [ -m max ] [ -z n ] [-o tree_out_file] [-w 0/1]


        -F model: model should be read in from file 'model'
                  (MPS format is assumed unless -D is also present)
        -L model: LP format model should be read in from file 'model'
        -D data: model is in AMPL format and data is in file 'data'
        -T dir: run test with MIPLIB3 models
        -h: help
        -f file: read parameters from parameter file 'file'
        -d: stop at first feasible solution
        -a 0/1: whether to use primal heuristics
        -b 0/1: whether to use reliability branching
        -s cands: use at most 'cands' candidates for strong branching
        -l 0/1: whether to impose a limit on strong branching time
        -q 0/1: whether or not to tighten root bounds
        -r 0/1: whether or not to do reduced cost tightening
        -j 0/1: whether or not to generate cgl cuts
        -w 0/1: whether or not to use hot starting in strong branching
        -e n: set pre-processing level to 'n'
        -i iters: allow a max of 'iters' iterations in presolve
        -t time: set wallclock time limit to 'time'
        -g gap: set gap limit to 'gap'
        -n nodes: set node limit to 'nodes'
        -u ub: use initial upper bound 'ub'
        -p procs: allow 'procs' additional threads or processors
        -k i: use node selection rule 'i'
        -v n: set verbosity to level 'n'
        -c i: use rule 'i' to compare candidates
        -m max: allow a max of 'max' cuts to enter per iteration
        -z n: set diving threshold to 'n'
        -o file: output vbc-like tree information to file 'file'
```
		
### Using the SYMPHONY interactive optimizer

To use SYMPHONY's Interactive shell, run the executable name without any
command line arguments. Then type "help" or "?" to see a list of available
commands which are as follows for this version:

```
	load      : read a problem in mps or ampl format
	solve     : solve the problem
	lpsolve   : solve the lp relaxation of the problem
	set       : set a parameter
	display   : display optimization results and stats
	reset     : restart the optimizer
	help      : show the available commands/params/options	

	quit/exit : leave the optimizer
```
	
So, if you want to load and solve an ampl/gmpl file, you will need to type
"load sample.mod sample.dat" and then "solve". 

### Using the callable library

To use SYMPHONY as a generic callable library, compile SYMPHONY as described
above. The library that is created along with the solver itself can be linked
to using the API described in the user's manual. For examples of using the
callable library in this way, see the Examples/ subdirectory.

## DEVELOPING CUSTOM APPLICATIONS

To customize SYMPHONY by implementing the custom callback functions, simply
modify the files in the SYMPHONY/Applications/USER/ subdirectory, as described
in the user's manual and follow the compilation procedures in the file
SYMPHONY/Applications/USER/README. There are a number of sample applications
available as examples of how to do this kind of development with SYMPHONY.
These include solvers for the matching problem, the set partitioning problem
(simple and advanced versions), the vehicle routing and traveling salesman
problems, and the mixed postman problem. These applications are distributed as
separate packages and can be downloaded from http://www.branchandcut.org.
There is a white paper that guides the user through the development of the
matching solver.

## CURRENT TESTING STATUS

SYMPHONY can now be used in a very large number of possible configurations and
we simply aren't able to test them all. Below is a rough idea of the testing
status of various configurations to date. If you need a certain configuration,
I would be happy to help you get it running. Please let me know.

## LP INTERFACES

**The native interfaces for OSL and CPLEX have now been deprecated**
**Only LP solvers with OSI interfaces are supported**

Well tested: CPLEX, CLP

Well tested, but have some stability or other issues: GLPK

Compiled, but not well tested: SPX

## TESTED CONFIGURATIONS

### SEQUENTIAL

Sequential configurations are now automatically built and tested on Linux, OS X, and Windows using
 * [Travis-CI](https://travis-ci.org/coin-or/symphony)
 * [Appveyor](https://ci.appveyor.com/project/tkralphs/symphony)

### SHARED MEMORY PARLLEL (OpenMP)

Builds and passes unit test with gcc 4 and 5 and CLP on LINUX.

### DISTRIBUTED MEMORY PARALLEL (PVM)

Known configurations that build and pass unit test

- gcc 4.* on LINUX with PVM 3.4

### APPLICATIONS

- SYMPHONY (used as a generic MILP solver): Well tested.

- MATCH (matching): Tested, but not very extensively.

- MPP (mixed postman problem): Tested, but not very extensively.

- VRP (vehicle routing problem): Well tested.

- CNRP (capacitates network routing problem): Well tested.

- MCKP (multi criteria knapsack problem): Well tested.

- SPP (set partitioning problem): Tested, but not very extensively.

- SPP+CUTS (set partitioning problem with cutting planes): Tested, but not very 
extensively.

### CUT GENERATORS

Cut generators are supplied by the Cut Generation Library (CGL). The cut
generators that are turned on by default have been well tested. Two cut
generators that are part ofthe CGL are turned off by default because of known
issues. These are lift and project cuts and the simple rounding cuts. The
generator for Gomory cuts works well, but has somenumerical issues. We found a
few cases where the optimal solution was not found when using the Gomory cut
generator, especially in combination with CPLEX. If the solver is not
performing as it should, try turning off some of the cut generators to see if
that fixes the problem. 

### EXTERNAL COIN-OR LIBRARIES

See the Depdencies file for a list of the external COIN-OR libraries on which
SYMPHONY depends.

### BUG REPORTS

To report a bug please file a ticket at 

https://github.com/coin-or/SYMPHONY/issues/new

## SUPPORT

### AUTHORS

SYMPHONY was jointly developed by Ted Ralphs (ted@lehigh.edu) and Laci Ladanyi
(ladanyi@us.ibm.com). Menal Guzelsoy (menal.guzelsoy@gmail.com) and Ashutosh
Mahajan (amahajan@iitb.ac.in.edu) have been instrumental in development since
version 5.0.

### ACKNOWLEDGEMENTS

SYMPHONY was developed with support from

* National Science Foundation (Grants CMMI-1435453, CMMI-0728011, DMI-0522796, DMI-0534862, DMS-9527124, CMMI-1130914)
* Texas ATP Grant 97-3604-010
* Cornell University
* Lehigh University
* Zuse Institute Berlin
* Research Campus Modal "Mathematical Optimization and Data Analysis 
Laboratories" funded by the German Federal Ministry of Education and Research
(BMBF Grant 05M14ZAM) and by the DFG SFB/Transregio 154

## CHANGELOG

### Release 5.6.17
  * Update appveyor
  * Fix several reported bugs (see PRs 10-12, Issue 2)

### Release 5.6.16
  * Fix problem with appveyor configuration

### Release 5.6.15
  * Fix for configuration issue with OpenMP when building with Visual Studio
    compiler under Msys2
  * Fix for bugs in PVM version
  * Fix for bugs in computing lower bounds
  * Fix for compilation error with gcc 6
  * Other minor fixes
  * Enabling binary uploads with BinTray

### Release 5.6.14
  * Fixing small bug with re-setting environment in user applications.
  * Fixing some memory errors arising with applications when extra variables are used.
  * Fixing small bug with tracking variable indices in branching.
  * Moving code inside critical block to prevent memory access errors in shared memory parallel mode.
  * Added switches for turning hot starting on and off
  * Updates to documentation
  * Small fixes
  * Added support for Travis and Appveyor

### Release 5.6.13
  * Release to update externals and pick up bug fixes in other projects

### Release 5.6.12
  * Fixed function for determining duals and reduced costs.
  * Making it possible to build with cut validity checking enabled.
  * Fixed bug with re-using of environment for new instances.
  * Added parameter that allows saving of LP relaxations for debugging.
  * Added function for writing LP files.
  * Fixed bug that arose when we fixed a variable in strong branching (now, we keep going with LP loop when this happens).
  * Fixed long-standing bug that arose when child 0 could be pruned while generating children.

### Release 5.6.11
  * Updated externals

### Release 5.6.10
  * Fixed bug with using more the 1 process in PVM
  * Print to stderr on ctrl-c
  * Fixed double free with prep level < 1

### Release 5.6.9
  * Fixed memory leak
  * Fixed double free when nodes are retained in memory after pruning
  * Added ability to access solution pool after solve to retrieve additional suboptimal solutions.
  * Updates to documentation 

### Release 5.6.8
  * Fix to dependency linking.
  * Fix for installation with ```DESTDIR```

### Release 5.6.7
  * Fixes to distributed parallel (PVM) version.
  * Enable primal heuristics in distributed version.
  * Update externals to most recent stables.
  * Make dependency linking default.

### Release 5.6.6:

 * Disabling pre-processor for multicriteria instances.

### Release 5.6.5:

 * Added explicit dependence on libgomp, which is needed for linking with 
compilers that don't supprt OpenMP (clang on OS X)

### Release 5.6.4:

 * Fix to pkgconfig file to add flags for OpenMP.

 * Fixes for documentation.

 *  More fixes for dependency linking.

### Release 5.6.3:

 * Fixes to applications to allow some preprocessing, which is needed for
some primal heuristics to work.

 * Fixes to preprocessor settings so that the minimal amount of preprocessing
is always done.

 *  Fixes to some methods so they still work preprely even when preprocessing is
not done.

 *  Fixes to pre-processor for applications that construct the LP relaxation 
algorithmically. 

 * Fix to pkgconfig file for applications.

 * Fix for dependency linking.

 * Other small bug fixes.

### Release 5.6.2:

 * Updates and fixes to manual and documentation files.

 * Fixes for configuring with PVM.

 *  Fixes to allow dependency linking with the application library. 

 *  Bug fix for reliability branching. 

 * Bug fix for addition of column cuts

 * Updates to externals to fix bugs in dependent projects.

### Release 5.6.1:

 * Small fixes for OpenMP

### Release 5.6.0:

 * Major re-design of shared memory parallel mode for increased efficiency and stability.

 * Fixes for distributed memory parallel version (PVM)

 *  Fixes for bicriteria version

### Release 5.5.7:

 * More updates to build harness

### Release 5.5.6:

 * More updates to build harness

### Release 5.5.5:

 * More updates to build harness

### Release 5.5.4:

 * Fix memory leak
 * Delete superfluous header file
 *  More updates to build harness

### Release 5.5.3:

 * More updates to build harness

### Release 5.5.2:

 * Fix problems with Visual Studio project files
 * Update to build tools

### Release 5.5.1:

 * Fix bug that caused all user applications to crash

### Release 5.4.8:

 * Updates to MSVC++ files (applications now use property sheets and VRP app file is fixed).
 * Other fixes for build tools.

### Release 5.4.7:

 * Updates to documentation

### Release 5.5.0:

 * Improvements to preprocessing
 * Improvements to heuristics
 * Improvements to MSVC++ support
 * Bug fixes
 * Significant performance gains 

### Release 5.4.6:
 * More fixes to allow use of CPLEX as LP solver
 * Fixes to interface with GMPL

### Release 5.4.5:

 * Fixes to allow use of CPLEX as LP solver
 * Fixes to interface with GMPL

### Release 5.4.4:

 * Fixes for build system
 * Other minor fixes

### Release 5.4.3:

 * Updates to documentation.
 * Fix to allow box-constrained integer programs.
 *  Fix for GMPL integration
 *  Fix for readline versions

### Release 5.4.2:

 * Updates to MSVC++ version 10 files

### Release 5.4.1

 * Addition of MSVC++ version 9 files

### Release 5.4.0:

 * Change license to EPL.

 * Support for MSVC++ version 10 added.

 *  Support for BuildTools version 0.7 to incoorporate recent enhancements, including proper library versioning in Linux, prohibiting installation of private headers, etc.

 *  Enhancements to unit testing.

 * Updating externals to new stable versions of dependent projects.

### Release 5.3.4:

 * Fixes to the shared memory parallel version (OpenMP). It is now pretty
stable, though some minor memory conflict conditions may arise (infrequently).

 * Fixes to allow all applications to build and run properly.

 *  Updates to documentation.

### Release 5.3.3:

 * Fixes to the build system.

### Release 5.3.2:

 * Fixes to the build system.

### Release 5.3.1:

 * Fixes to the build system.

### Release 5.3.0:

 * Major changes to the build system to allow buinding against installed
binaries, provide pkg-config support, etc.

### Release 5.2.4:

 * Fixes to restore functionality of the bicriteria solution capability.

 * Fixes to examples.

### Release 5.2.3:

 * Updates to manual.

 * Added hooks to enable the use of VRPH (https://projects.coin-or.org/VRPH) within the VRP solver.

### Release 5.2.2:

 * Bug fix release.

### Release 5.2.1: 

 * Bug fix release.

### Release 5.2.0:

 * SYMPHONY has a preprocessor now.

 * Feasibility pump primal heuristic implemented.

 *  Reliability branching is now the default branching strategy.

 *  Several new statistics now part of default output.

 * Correct setting of granularity of objective function value by calculating
   GCD of coefficients.

 * Several changes in management of valid inequalities, quality checks and
   detection of duplicacy.

 * Minor changes in management of LP solver interface.

 * Several small bug-fixes and improvements.

### Release 5.1.10:

 * New dependencies.

### Release 5.1.9:

 * New dependencies.

### Release 5.1.8:

 * Introduced use of LP hot starting.

 * Improved management of cut generation.

 *  Updated externals

 *  Minor bug fixes

### Release 5.1.7:

 * Minor bug fixes

### Release 5.1.6:

 * Only a single header file (symphony.h) needs to be installed and user 
applications only need to be able to find this one header file.

 * Fixes to MSVC++ project files.

 *  Removed dependence on qsortucb routines.

### Release 5.1.5:

 * Added support for automatic download and build of Glpk (for reading of GMPL
files).

 * Minor bugs fixed and compiler warnings eliminated.

 *  Updates to MS Visual Studio files.

 *  Added short installation verification test.

### Release 5.1.4:

 * Added ability to read files in LP format.

 * Additional configuration options.

 *  Support for new classes of cutting planes.

 *  Improved algorithm control mechanism.

 * Improved output format and additional output options.

 * Improved signal handling.

 * Shared memory parallel version tested with OpenMP in Linux and Windows.

 * Added release configuration to MSVC++ build files.

 * Improved warm starting.

 * Fixes for configuration with SoPlex and Xpress.

 * Fixed configuration on PowerPC architectures.

### Release 5.1.3:

 * Support for building static executables in Unix-like environments.

 * Improved signal-catching behavior in Unix-like environments.

 *  Updated documentation.

### Release 5.1.2:

 * Update of externals.

 * Updated documentation.

### Release 5.1.1:

 * Fixes for building in the Solaris operating system.

 * Fixes for using the GNU autotools to build with the cl compiler.

 * Fixes for sym.mak file in order to allow building with MSVC++ nmake utility.

 *  Fixes for building the unit test in the MSVC++ IDE.

 * Updated documentation

### Release 5.1.0:

 * SYMPHONY now has an interactive optimizer that can be used through a
command shell. In both the sequential and parallel configurations, the user
can set parameters, load and solve instances interactively, and display
results and statistics (see below).

 * SYMPHONY now supports automatic configuration using the new COIN-OR build
system and the GNU autotools.Using autotools utilities, it is now possible to
build SYMPHONY in most operating systems and with most common compilers
compilers without user intervention.

 * Both the distributed and shared memory parallel configurations are now
fully debugged, tested, and supported. The user can now build and execute
custom SYMPHONY applications in parallel, as well as solving generic MILPs in
parallel "out of the box."

 * There are now additional options for warm starting. The user can trim the
warm starting tree before starting to resolve a problem. More specifically,
the user can decide to initiate warm starting with a predefined partition of
the final branch-and-cut tree resulting from a previous solution procedure.
This partition can include either a number of nodes created first during the
solution procedure or all of the nodes above a given level of the tree.

 * The COIN-OR repository, the current host of SYMPHONY has recently undergone 
some significant improvements of its own that have resulted in improved 
services to users. These include: 

   * SYMPHONY has a new development Web site, where users can submit trouble
     tickets, browse the source code interactively, and get up-to-date
     information on development. The address of the new site is
     https://projects.coin-or.org/SYMPHONY.

   * SYMPHONY is now hosted using subversion, a version control system with
     features vastly improved over CVS, the previous hosting software. This
     has required some reorganization and renaming of the header files.

   * SYMPHONY is now more tightly integrated with other COIN-OR projects. Due
     to improved procedures for producing stable releases, it will now be much
     easier for us to determine the exact version of SYMPHONY and all other
     COIN projects you are using when you report a bug.

   * SYMPHONY is now distributed with all COIN software needed to build a
     complete solver. Previously, other COIN softrware packages had to be
     downloaded and installed separately.

 * Two features have been deprecated and are no longer supported:

   * The native interfaces to OSL and CPLEX are now deprecated and no longer
supported. These solvers can be called through the COIN-OR OSI interface.

   * Column generation functionality has also been officially deprecated. For
     now, there are a number of other software packages that offer better
     functionality than SYMPHONY for implementing branch and price algorithms.

 * CHANGES TO THE USER INTERFACE (FROM SYMPHONY 5.0)

   * There was one minor change to the user callback API from version 5.0 to
     5.1. The user can now execute a primal heuristic in the
     user_is_feasible() callback and return the solution to SYMPHONY. The API
     for the user_is_feasible() subroutine is now
     ```C
     int user_is_feasible(void *user, double lpetol, int varnum, int *indices,
		          double *values, int *feasible, double *objval,
		          char branching, double *heur_solution)
     ```
Any feasible solution can be passed (in dense format) through the last
argument to this function.

   * Several new subroutines were added to the callable library API.

   * The name of the header file containing the SYMPHONY API has been changed
     from ```symphony_api.h``` to ```symphony.h``` (though the former has been
     retained for backword compatibility purposes).

