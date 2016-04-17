#ifndef VUMETEREFFECT_H
#define VUMETEREFFECT_H

#include "RenderableEffect.h"
#include "../RenderBuffer.h"
#include <string>
#include <list>

class VUMeterEffect : public RenderableEffect
{
    public:
        VUMeterEffect(int id);
        virtual ~VUMeterEffect();
        virtual void Render(Effect *effect, const SettingsMap &settings, RenderBuffer &buffer) override;
        void Render(RenderBuffer &buffer,
                    int bars, const std::string& type, const std::string& timingtrack, int sensitivity, const std::string& shape, bool slowdownfalls, int startnote, int endnote);
		virtual void SetDefaultParameters(Model *cls) override;
	protected:
        virtual wxPanel *CreatePanel(wxWindow *parent) override;
		int DecodeType(std::string type);
		void RenderSpectrogramFrame(RenderBuffer &buffer, int bars, std::list<float>& lastvalues, bool slowdownfalls, int startnote, int endnote);
		void RenderVolumeBarsFrame(RenderBuffer &buffer, int bars);
		void RenderWaveformFrame(RenderBuffer &buffer, int bars);
		void RenderTimingEventFrame(RenderBuffer &buffer, int bars, int type, std::string timingtrack, std::list<int> &timingmarks);
        void RenderOnFrame(RenderBuffer &buffer);
        void RenderOnColourFrame(RenderBuffer &buffer);
        void RenderPulseFrame(RenderBuffer &buffer, int fadeframes, std::string timingtrack, int& lasttimingmark);
        void RenderTimingEventColourFrame(RenderBuffer &buffer, int& colourindex, std::string timingtrack);
        void RenderIntensityWaveFrame(RenderBuffer &buffer, int bars);
		void RenderLevelPulseFrame(RenderBuffer &buffer, int fadeframes, int sensitivity, int& lasttimingmark);
		void RenderLevelShapeFrame(RenderBuffer &buffer, const std::string& shape, float& lastsize, int scale, bool slowdownfalls);
		void DrawBox(RenderBuffer& buffer, int startx, int endx, int starty, int endy, xlColor& color1);
		void DrawCircle(RenderBuffer& buffer, int x, int y, float radius, xlColor& color1);
		void DrawDiamond(RenderBuffer& buffer, int centerx, int centery, int size, xlColor& color1);
};

#endif // VUMETEREFFECT_H
