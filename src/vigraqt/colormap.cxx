#include "linear_colormap.hxx"

ColorMap::~ColorMap()
{
}

class FireMap : public LinearColorMap
{
public:
	FireMap()
	{
		transitionPoints_.push_back(TransitionPoint(0.0,   Color(0, 0, 0)));
		transitionPoints_.push_back(TransitionPoint(1.0/3, Color(255, 0, 0)));
		transitionPoints_.push_back(TransitionPoint(2.0/3, Color(255, 255, 0)));
		transitionPoints_.push_back(TransitionPoint(1.0,   Color(255, 255, 255)));
	}
};

class NegMap : public LinearColorMap
{
public:
	NegMap()
	{
		transitionPoints_.push_back(TransitionPoint(0.0,   Color(0, 0, 255)));
		transitionPoints_.push_back(TransitionPoint(0.0,   Color(0, 0, 0)));
		transitionPoints_.push_back(TransitionPoint(1.0/3, Color(255, 0, 0)));
		transitionPoints_.push_back(TransitionPoint(2.0/3, Color(255, 255, 0)));
		transitionPoints_.push_back(TransitionPoint(1.0,   Color(255, 255, 255)));
	}
};

class GrayMap : public LinearColorMap
{
public:
	GrayMap()
	{
		transitionPoints_.push_back(TransitionPoint(0.0,   Color(0, 0, 0)));
		transitionPoints_.push_back(TransitionPoint(1.0,   Color(255, 255, 255)));
	}
};

ColorMap *createColorMap(BuiltinColorMap cm)
{
    ColorMap *result = NULL;
    switch(cm)
    {
      case CMLinearGray:
          result = new GrayMap();
          break;
      case CMFire:
          result = new FireMap();
          break;
      case CMFireNegativeBlue:
          result = new NegMap();
          break;
    }
	result->setDomain(0.0, 1.0);
	return result;
}
