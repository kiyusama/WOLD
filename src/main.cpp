#include "PacketSender.hpp"
#include <cstdlib>
#include <dpp.h>

// discord botのトークン
const std::string token = std::getenv("DISCORD_TOKEN");

int main() {
  PacketSender wolSender;

  dpp::cluster bot(token);

  bot.on_log(dpp::utility::cout_logger());

  // コマンドの実装
  bot.on_slashcommand([&wolSender](const dpp::slashcommand_t &event) {
    if (event.command.get_command_name() == "test") {
      event.reply("ok!");
      wolSender.sendWOL();
    }
  });

  bot.on_ready([&bot](const dpp::ready_t &event) {
    if (dpp::run_once<struct register_bot_commands>()) {
      bot.global_command_create(
          dpp::slashcommand("test", "this is a test command", bot.me.id));
    }
  });

  // ボットの起動
  bot.start(dpp::st_wait);
  return 0;
}
