/*===========================================================================*/
/*                                                                           */
/* This file is part of the SYMPHONY Branch, Cut, and Price Library.         */
/*                                                                           */
/* SYMPHONY was jointly developed by Ted Ralphs (tkralphs@lehigh.edu) and    */
/* Laci Ladanyi (ladanyi@us.ibm.com).                                        */
/*                                                                           */
/* (c) Copyright 2000-2003 Ted Ralphs. All Rights Reserved.                  */
/*                                                                           */
/* This software is licensed under the Common Public License. Please see     */
/* accompanying file for terms.                                              */
/*                                                                           */
/*===========================================================================*/

#define COMPILING_FOR_MASTER

/*===========================================================================*/

#define CALL_FUNCTION(f)
if ((termcode = f) < 0){                                                    \
   printf("Error detected: termcode = %i\n", termcode);                     \
   printf("Exiting...\n\n");                                                \
   exit(termcode);                                                          \
}

/*===========================================================================*\
 * This file contains the main() for the master process.
\*===========================================================================*/

#if defined(USE_OSI_INTERFACE) && !defined(USER_MAIN) 

#include "OsiSymSolverInterface.hpp"

int main(int argc, char **argv)
{
   OsiSymSolverInterface si;

   /* Parse the command line */
   si.parseCommandLine(argc, argv);
   
   /* Read in the problem */
   si.loadProblem();

   /* Find a priori problem bounds */
   si.findInitialBounds();

   /* Solve the problem */
   si.branchAndBound();
   
   return(0);
}

#elif !defined(USER_MAIN)

#include "master.h"

int main(int argc, char **argv)
{
   problem *p = sym_open_environment();

   if (!p){
      printf("Error initializing environement\n");
      exit(0);
   }
   
   CALL_FUNCTION( sym_parse_command_line(p, argc, argv) );

   CALL_FUNCTION( sym_load_problem(p) );

   CALL_FUNCTION( sym_find_initial_bounds(p) );

   CALL_FUNCTION( sym_solve(p) );

   CALL_FUNCTION( sym_close_environment(p) );

   return(0);
}

#endif
