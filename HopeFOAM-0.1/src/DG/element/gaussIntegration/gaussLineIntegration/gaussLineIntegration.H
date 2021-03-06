/*--------------------------------------------------------------------------------------
|     __  ______  ____  ______ |                                                       |
|    / / / / __ \/ __ \/ ____/ | HopeFOAM: High Order Parallel Extensible CFD Software |
|   / /_/ / / / / /_/ / __/    |                                                       |
|  / __  / /_/ / ____/ /___    |                                                       |
| /_/ /_/\____/_/   /_____/    | Copyright(c) 2017-2017 The Exercise Group, AMS, China.|
|                              |                                                       |
----------------------------------------------------------------------------------------

License
    This file is part of HopeFOAM, which is developed by Exercise Group, Innovation 
    Institute for Defence Science and Technology, the Academy of Military Science (AMS), China.

    HopeFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.

    HopeFOAM is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with HopeFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::gaussLineIntegration

Description
    gauss interpolation for Line Element

SourceFiles
    gaussLineIntegration.C


Author
    Xu Liyang (xucloud77@gmail.com)
\*---------------------------------------------------------------------------*/

#ifndef gaussLineIntegration_H
#define gaussLineIntegration_H

#include "gaussIntegration.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

/*---------------------------------------------------------------------------*\
                       Class gaussLineIntegration Declaration
\*---------------------------------------------------------------------------*/

class gaussLineIntegration
:
    public gaussIntegration
{
	// Private data

	 // Private Member Functions

        //- Disallow default bitwise copy construct
        gaussLineIntegration(const gaussLineIntegration&);

        //- Disallow default bitwise assignment
        void operator=(const gaussLineIntegration&);

public:

    //- Runtime type information
    TypeName("line");

    // Constructors

        //- Construct
        gaussLineIntegration(const baseFunction&);

    // Member functions

        //-
        void initFaceRotateIndex();
        //- calculate physical node location
        vectorList gaussCellNodesLoc(const vectorList&)const;
        //- calculate cell dr/dx
        tensorList cellDrdx(const tensorList&)const;
        //- calculate cell cell integration factors
        scalarList cellWJ(const tensorList&)const;
        //- calculate cell cell integration factors
        void faceNxWJ(const tensorList&, label, vectorList&, scalarList&)const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //