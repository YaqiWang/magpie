/**********************************************************************/
/*                     DO NOT MODIFY THIS HEADER                      */
/* MAGPIE - Mesoscale Atomistic Glue Program for Integrated Execution */
/*                                                                    */
/*            Copyright 2017 Battelle Energy Alliance, LLC            */
/*                        ALL RIGHTS RESERVED                         */
/**********************************************************************/

#include "PKAFunction.h"

template<>
InputParameters validParams<PKAFunction>()
{
  InputParameters params = validParams<PKAEmpiricalBase>();
  params.addParam<FunctionName>("pka_rate", 1e-8, "PKA rate per unit volume (uses mesh units defined in the rasterizer and moose time units)");
  params.addRequiredParam<FunctionName>("Z", "PKA nuclear charge");
  params.addRequiredParam<FunctionName>("m", "PKA mass in amu");
  params.addRequiredParam<FunctionName>("E", "PKA energy in eV");
  return params;
}

PKAFunction::PKAFunction(const InputParameters & parameters) :
    PKAEmpiricalBase(parameters),
    _pka_rate(getFunction("pka_rate")),
    _Z(getFunction("Z")),
    _m(getFunction("m")),
    _E(getFunction("E")),
    _time(_fe_problem.time())
{
}