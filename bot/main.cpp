#include "dpp/dpp.h"

#include <string>

#include "commands/exec_command.h"
#include "cryptography/gen_password.h"
#include "cryptography/encryption/xor_encryption.h"

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
    dpp::cluster bot(BOT_TOKEN, dpp::i_default_intents | dpp::i_message_content);

    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([](const dpp::slashcommand_t &event) {
        dpp::interaction interaction = event.command;
        dpp::command_interaction cmd_data = interaction.get_command_interaction();

        if (interaction.get_command_name() == "cryptography") {

            if (cmd_data.options[0].name == "password") {
                if (cmd_data.options[0].options[0].name == "generate") {
                    int64_t l   = std::get<int64_t>(cmd_data.options[0].options[0].options[0].value);
                    bool a      = std::get<bool>(cmd_data.options[0].options[0].options[1].value);
                    bool n      = std::get<bool>(cmd_data.options[0].options[0].options[2].value);
                    bool s      = std::get<bool>(cmd_data.options[0].options[0].options[3].value);

                    std::string password = silly::utils::gen_password(l, a, n, s);
                    event.reply(password);
                }
            }

            else if (cmd_data.options[0].name == "encryption") {
                if (cmd_data.options[0].options[0].name == "xor_chipper") {
                    std::string t = std::get<std::string>(cmd_data.options[0].options[0].options[0].value);
                    std::string k = std::get<std::string>(cmd_data.options[0].options[0].options[1].value);

                    std::string result = silly::utils::xor_encryption(t, k);
                    event.reply(dpp::message(result).set_flags(dpp::m_ephemeral));
                }
            }
        }
    });

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

    bot.on_slashcommand([](const dpp::slashcommand_t &event) {
        if (event.command.get_command_name() == "shell") {
            std::string param = std::get<std::string>(event.get_parameter("query"));
            std::string result = silly::utils::exec(param.c_str());
            event.reply(result);
        }
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {

            // Commands
            dpp::slashcommand help_command("help", "Ask Silly about some of the things she can do", bot.me.id);
            dpp::slashcommand fortune_command("fortune", "Ask Silly for a nice quote", bot.me.id);
            dpp::slashcommand search_command("search", "Tell Silly what it is you want to find", bot.me.id);
            dpp::slashcommand shell_command("shell", "Ask Silly to run bash(default) shell", bot.me.id);
            dpp::slashcommand cryptography_command("cryptography", "...", bot.me.id);

            // Commands Options
            search_command.add_option(
                dpp::command_option(dpp::co_string, "query", "What you think...", true)
            );

            shell_command.add_option(
                dpp::command_option(dpp::co_string, "query", "write your shell command here...", true)
            );

            cryptography_command
            .add_option(
                dpp::command_option(dpp::command_option(dpp::co_sub_command_group, "password", "Manage Password"))
                .add_option(dpp::command_option(dpp::co_sub_command, "generate", "Generate Password")
                    .add_option(dpp::command_option(dpp::co_integer, "length", "length pass", true))
                    .add_option(dpp::command_option(dpp::co_boolean, "use_alpha", "use alpha", true))
                    .add_option(dpp::command_option(dpp::co_boolean, "use_numeric", "use numeric", true))
                    .add_option(dpp::command_option(dpp::co_boolean, "use_special", "use special symbol", true))
                )
            )
            .add_option(
                dpp::command_option(dpp::command_option(dpp::co_sub_command_group, "encryption", "Covert Text into an encoded format"))
                .add_option(dpp::command_option(dpp::co_sub_command, "xor_chipper", "Encrypt method use of the operator XOR")
                    .add_option(dpp::command_option(dpp::co_string, "plaintext", "Enter your plaintext", true))
                    .add_option(dpp::command_option(dpp::co_string, "encrypt_key", "Key is like 'A', 'ABC', 'XYZ321', etc.", true))
                )
            );


            // Register Commands
            bot.global_command_create(help_command);
            bot.global_command_create(fortune_command);
            bot.global_command_create(search_command);
            bot.global_command_create(shell_command);
            bot.global_command_create(cryptography_command);
        }
    });

    bot.start(dpp::st_wait);
}
