#ifndef __TENGINE_RENDERMODULE__
#define __TENGINE_RENDERMODULE__


#include "TEngine_Module.h"

#include "fx.h"

namespace TsiU
{
	class Renderer;
	class RenderWindowMsg;

	class RenderModule : public IModule
	{
	public:
		RenderModule(u32 _uiWidth, u32 _uiHeight, StringPtr _strTitle, Bool _bIsWindow);
		~RenderModule();

		virtual void Init();
		virtual void RunOneFrame(float _fDeltaTime);
		virtual void UnInit();

		inline Renderer* GetRenderer(){
			return m_poRenderer;
		}
		inline RenderWindowMsg* GetRenderWindowMsg(){
			return m_poRenderWindowMsg;
		}
		inline FXApp* GetGUIApp(){
			return m_poApp;
		}
		inline FXMainWindow* GetGUIMainWindow(){
			return m_poMainWindow;
		}
		void SetRendererWin(Udef _poWin){
			m_poRendererWin = _poWin;
		}

	private:		
		class FpsTimer
		{
		public:
			FpsTimer();

			f32		GetFPS() const;
			void	SetTimer(f32 _fTotalTime);

		private:
			f32		m_fLastTime;
			f32		m_fFPS;
		};

		Udef				m_poRendererWin;
		Renderer*			m_poRenderer;
		RenderWindowMsg*	m_poRenderWindowMsg;

		FXApp*				m_poApp;
		FXMainWindow*		m_poMainWindow;
		
		FpsTimer			m_FpsTimer;
	};
}

#endif