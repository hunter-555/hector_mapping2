//=================================================================================================
// Copyright (c) 2013, Johannes Meyer and contributors, Technische Universitat Darmstadt
// All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the Flight Systems and Automatic Control group,
//       TU Darmstadt, nor the names of its contributors may be used to
//       endorse or promote products derived from this software without
//       specific prior written permission.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//=================================================================================================

#ifndef HECTOR_MAPPING2_MATCHER_CERES_H
#define HECTOR_MAPPING2_MATCHER_CERES_H

// HAVE_CERES is normally set by cmake. Just for debugging here...
#ifndef HAVE_CERES
  #define HAVE_CERES
#endif // HAVE_CERES

#ifdef HAVE_CERES

#include <hector_mapping2/matcher.h>
#include <ceres/ceres.h>

namespace hector_mapping {
namespace matcher {

class Ceres : public ScanMatcher
{
public:
  Ceres(const Parameters& params);
  virtual ~Ceres();

  virtual bool match(const OccupancyGridMapBase &map, const Scan &scan, MatchType options);
  virtual double evaluate(const OccupancyGridMapBase& map, const Scan& scan, const tf::Transform& pose, std::string *resultString, MatchType type) const;

private:
  class Solver;
  typedef boost::shared_ptr<Solver> SolverPtr;
  ceres::Solver::Options ceres_options_;
};

} // namespace matcher
} // namespace hector_mapping

#endif // HAVE_CERES
#endif // HECTOR_MAPPING2_MATCHER_CERES_H
