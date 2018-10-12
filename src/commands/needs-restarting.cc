/*---------------------------------------------------------------------------*\
                          ____  _ _ __ _ __  ___ _ _
                         |_ / || | '_ \ '_ \/ -_) '_|
                         /__|\_, | .__/ .__/\___|_|
                             |__/|_|  |_|
\*---------------------------------------------------------------------------*/
#include "needs-restarting.h"

#include "utils/messages.h"
#include "Zypper.h"

#include <zypp/PathInfo.h>

using namespace zypp;

NeedsRestartingCmd::NeedsRestartingCmd(const std::vector<std::string> &commandAliases_r) :
  ZypperBaseCommand (
    commandAliases_r,
    "needs-restarting",
    // translators: command description
    _("Check if the needs-reboot flag was set."),
    _("Checks if the needs-reboot flag was set by a previous update or install transaction."),
    DisableAll
  )
{}

zypp::ZyppFlags::CommandGroup NeedsRestartingCmd::cmdOptions() const
{
  return zypp::ZyppFlags::CommandGroup();
}

void NeedsRestartingCmd::doReset()
{
  return;
}

int NeedsRestartingCmd::execute( Zypper &zypp_r, const std::vector<std::string> &positionalArgs_r )
{
  if ( !positionalArgs_r.empty() )
  {
    report_too_many_arguments( help() );
    return ZYPPER_EXIT_ERR_INVALID_ARGS;
  }

  filesystem::Pathname rebootNeededFlag = filesystem::Pathname(zypp_r.globalOpts().root_dir) / "/var/run/reboot-needed";

  if ( filesystem::PathInfo( rebootNeededFlag ).isExist() ) {
    zypp_r.out().info( _("Core libraries or services have been updated.") );
    zypp_r.out().info( _("Reboot is required to ensure that your system benefits from these updates.") );
    return 1;
  }
  zypp_r.out().info( _("No core libraries or services have been updated.") );
  zypp_r.out().info( _("Reboot is probably not necessary.") );
  return 0;
}
