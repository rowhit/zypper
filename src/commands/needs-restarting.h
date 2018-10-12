/*---------------------------------------------------------------------------*\
                          ____  _ _ __ _ __  ___ _ _
                         |_ / || | '_ \ '_ \/ -_) '_|
                         /__|\_, | .__/ .__/\___|_|
                             |__/|_|  |_|
\*---------------------------------------------------------------------------*/
#ifndef ZYPPER_COMMANDS_NEEDS_RESTARTING_INCLUDED
#define ZYPPER_COMMANDS_NEEDS_RESTARTING_INCLUDED

#include "commands/basecommand.h"
#include "utils/flags/zyppflags.h"

class NeedsRestartingCmd : public ZypperBaseCommand
{
public:
  NeedsRestartingCmd ( const std::vector<std::string> &commandAliases_r );

  // ZypperBaseCommand interface
protected:
  zypp::ZyppFlags::CommandGroup cmdOptions() const override;
  void doReset() override;
  int execute(Zypper &zypp_r, const std::vector<std::string> &positionalArgs_r) override;
};

#endif
