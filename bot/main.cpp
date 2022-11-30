#include "dpp/dpp.h"
#include <string>

#include "commands/exec_command.h"

const std::string    BOT_TOKEN    = "";

std::string info_help()
{
    std::string info = "**DESCRIPTION**\n";
    info.append("      Play or ask for help to silly with some Silly abilities. You can communicate with him with the following magical commands\n\n");
    info.append("  **Commands**\n");
    info.append("    **/fortune**\n");
    info.append("      Ask Silly for a nice quote\n\n");
    info.append("    **/search** query\n");
    info.append("      Tell Silly what it is you want to find\n\n");
    info.append("    **/help**\n");
    info.append("      List all magical commands which Silly can Understand\n");

    return info;
}

int main() {
    dpp::cluster bot(BOT_TOKEN);
 
    bot.on_log(dpp::utility::cout_logger());
 
    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
         if (event.command.get_command_name() == "fortune") {
            std::string quotes = silly::utils::exec("fortune");
            event.reply(quotes);
        }
    });

    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
         if (event.command.get_command_name() == "help") {
            event.reply(info_help());
        }
    });

    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "search") {
            std::string param = std::get<std::string>(event.get_parameter("query"));
            std::string result = silly::utils::exec(std::string("tuxi -r " + param).c_str());
            event.reply(result);
        }
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            /*
            bot.global_command_create(
                dpp::slashcommand("fortune", "Give some quotes", bot.me.id),
                dpp::slashcommand("search", "Tell Silly what it is you want to find", bot.me.id)
            );
            */

            // Commands
            dpp::slashcommand help_command("help", "Ask Silly about some of the things she can do", bot.me.id);
            dpp::slashcommand fortune_command("fortune", "Ask Silly for a nice quote", bot.me.id);
            dpp::slashcommand search_command("search", "Tell Silly what it is you want to find", bot.me.id);

            // Commands Options
            search_command.add_option(
                dpp::command_option(dpp::co_string, "query", "What you think...", true)
            );

            // Register Commands
            bot.global_command_create(help_command);
            bot.global_command_create(fortune_command);
            bot.global_command_create(search_command);
        }
    });

    bot.start(dpp::st_wait);
}
