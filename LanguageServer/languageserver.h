#ifndef __LanguageServerPlugin__
#define __LanguageServerPlugin__

#include "CompileCommandsGenerator.h"
#include "LSPDetector.hpp"
#include "LanguageServerCluster.h"
#include "cl_command_event.h"
#include "plugin.h"

class LanguageServerPlugin : public IPlugin
{
    LanguageServerCluster::Ptr_t m_servers;
    IProcess* m_process = nullptr;

protected:
    void OnSettings(wxCommandEvent& e);
    void OnRestartLSP(wxCommandEvent& e);
    void OnInitDone(wxCommandEvent& event);
    void OnEditorContextMenu(clContextMenuEvent& event);
    void OnMenuFindSymbol(wxCommandEvent& event);
    void ConfigureLSPs(const std::vector<LSPDetector::Ptr_t>& lsps);

    void OnLSPStopAll(clLanguageServerEvent& event);
    void OnLSPStartAll(clLanguageServerEvent& event);
    void OnLSPRestartAll(clLanguageServerEvent& event);
    void OnLSPStopOne(clLanguageServerEvent& event);
    void OnLSPStartOne(clLanguageServerEvent& event);
    void OnLSPRestartOne(clLanguageServerEvent& event);
    void OnLSPConfigure(clLanguageServerEvent& event);
    void OnLSPDelete(clLanguageServerEvent& event);
    void OnLSPShowSettingsDlg(clLanguageServerEvent& event);
    void OnLSPEnableServer(clLanguageServerEvent& event);
    void OnLSPDisableServer(clLanguageServerEvent& event);
    wxString GetEditorFilePath(IEditor* editor) const;

public:
    LanguageServerPlugin(IManager* manager);
    virtual ~LanguageServerPlugin();

    //--------------------------------------------
    // Abstract methods
    //--------------------------------------------
    virtual void CreateToolBar(clToolBar* toolbar);
    /**
     * @brief Add plugin menu to the "Plugins" menu item in the menu bar
     */
    virtual void CreatePluginMenu(wxMenu* pluginsMenu);

    /**
     * @brief Unplug the plugin. Perform here any cleanup needed (e.g. unbind events, destroy allocated windows)
     */
    virtual void UnPlug();
};

#endif // LanguageServerPlugin
