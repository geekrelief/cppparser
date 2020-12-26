/*
 * Copyright 2018 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrLumaColorFilterEffect.fp; do not modify.
 **************************************************************************************************/
#ifndef GrLumaColorFilterEffect_DEFINED
#  define GrLumaColorFilterEffect_DEFINED
#  include "include/core/SkTypes.h"
#  include "src/gpu/GrCoordTransform.h"
#  include "src/gpu/GrFragmentProcessor.h"
class GrLumaColorFilterEffect : public GrFragmentProcessor
{
#  include "include/private/SkColorData.h"
public:
  SkPMColor4f constantOutputForConstantInput(const SkPMColor4f& input) const override
  {
        float luma = SK_ITU_BT709_LUM_COEFF_R * input.fR + SK_ITU_BT709_LUM_COEFF_G * input.fG +
                     SK_ITU_BT709_LUM_COEFF_B * input.fB;
        return {0, 0, 0, SkTPin(luma, 0.0f, 1.0f)};
    }
  static std::unique_ptr<GrFragmentProcessor> Make()
  {
        return std::unique_ptr<GrFragmentProcessor>(new GrLumaColorFilterEffect());
    }
  GrLumaColorFilterEffect(const GrLumaColorFilterEffect& src);
  std::unique_ptr<GrFragmentProcessor> clone() const override;
  const char* name() const override
  { return "LumaColorFilterEffect"; }
private:
  GrLumaColorFilterEffect()
    :  INHERITED(kGrLumaColorFilterEffect_ClassID,
                        (OptimizationFlags)kConstantOutputForConstantInput_OptimizationFlag) 
    {
    }
  GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;
  void onGetGLSLProcessorKey(const GrShaderCaps&, GrProcessorKeyBuilder*) const override;
  bool onIsEqual(const GrFragmentProcessor&) const override;
  GR_DECLARE_FRAGMENT_PROCESSOR_TEST
  typedef GrFragmentProcessor INHERITED;
};
#endif
