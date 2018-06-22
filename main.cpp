#include <iostream>
#include <string.h>
#include <locale.h>
#include "buydventures.h"
#define tamanho 10

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL));

    Tabuleiro player;
    geraCasas(&player);

    char opt;
    int aux = 0;

    //Gameplay
    cout << "██████████████████████████████ BEM VINDO AO JOGO \"BuyDventure: Uma aventura na dungeon das compras\"! ██████████████████████████████" << endl;
    cout << "█ Nesse jogo você passeia por uma dungeon cheia de vendedores dispostos a te vender os mais doidos itens de todo o reino, e fica  █" << endl <<
         "█ ao seu julgamento comprar tais itens ou não...                                                                                  █" << endl
         << "█ Mas lembre-se: Cada item influencia nas conquistas ao final do jogo, por isso fique esperto! Cada coisa irá contar!             █" << endl
         << "█ Ah, já ia esquecendo de avisar, tem uns GOBLINS que ficam importunando a vida de quem passeia pela dungeon...                   █" << endl
         << "█ Tome cuidado, além de comerem qualquer coisa, inclusive todos seus itens... Ainda bem que são alérgicos a ferro...              █" << endl
         << "█                                                                                                                                 █" << endl
         << "█ A dungeon tem 5 goblins e 5 baús escondidos por aí, então escolha bem os passos que irá tomar...                                █" << endl
         << "█████████████████████████████████████████████████ DICAS PARA AS CONQUISTAS ████████████████████████████████████████████████████████" << endl
         << "█ 1) VERGONHA                                                                                                                     █" << endl
         << "█ 2) Desperdício de tempo                                                                                                         █" << endl
         << "█ 3) Era melhor investir na poupança                                                                                              █" << endl
         << "█ 4) Indiana Jones                                                                                                                █" << endl
         << "█ 5) Minecraft                                                                                                                    █" << endl
         << "█ 6) Repelente                                                                                                                    █" << endl
         << "█ 7) Lá vem a noiva...                                                                                                            █" << endl
         << "█ 8) McDungeon                                                                                                                    █" << endl
         << "█ 9) É HEXA!                                                                                                                      █" << endl
         << "█ 10) 6 MIL DÓL                                                                                                                   █" << endl
         << "█ 11) Já é jogos                                                                                                                  █" << endl
         << "███████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████ " << endl << endl;
    cout << "█ Vamos começar? (S)im ou (S)im?" << endl;
    cin >> opt;

    if(toupper(opt) == 'S'){
        while(player.pos < 25){
            //Andar
            if(player.pos >= 23){
                cout << "█ Finalizar o jogo? (S)im ou (N)ão?" << endl;
                cin >> opt;
                while(toupper(opt) != 'S' && toupper(opt) != 'N'){
                    cout << "█ Input inválido, escreva novamente..." << endl;
                    cin >> opt;
                }
                if(toupper(opt) == 'S' || toupper(opt) == 'N'){
                    cout << "█ Fim de jogo! Agora deixa eu analisar seu inventário rapidinho..." << endl;
                    if(pilhaVazia(player.inv)){
                        if(player.gold < 100){
                            cout << "Você saiu pior do que você entrou… Você é realmente ruim nisso… Não tem nem muito o que eu comentar aqui… Você envergonha seus antepassados…" << endl;
                        }else if(player.gold >= 100 && player.gold < 200){
                            cout << "Bem, você de fato ganhou um dinheirinho… Podia ter alguns itens pra chamar atenção pelo menos, mas assim tá ok, parabéns" << endl;
                        }else if(player.gold == 100){
                            cout << "Se você entrou do jeito que saiu, então por que veio? Que desperdício de tempo viu…" << endl;
                        }else if(player.gold == 200){
                            cout << "Uau! Você realmente não veio pra brincadeira! Achou todos os tesouros dos quais já ouvi falar! Já pensou em jogar na loteria?" << endl;
                        }
                    }
                    while(!pilhaVazia(player.inv)){
                        string lastItem = desempilha(player.inv);
                        cout << "█ Um(a) " << lastItem << "..." << endl;
                        if((lastItem == loja[0] || lastItem == loja[1]) || lastItem == loja[2]){
                            player.fim[0] += 1;
                            if(player.fim[0] == 3)
                                cout << "██ Er… Acho que você caiu no jogo errado, você devia é estar jogando aquele joguinho sueco de quebrar árvores e pegar pedras preciosas… Mas o que realmente me surpreende é você ter passado por todos os GOBLINS com essas pedras! Fazem parte da refeição favorita deles!" << endl;
                        }else if(lastItem == loja[3] || lastItem == loja[4]){
                            player.fim[1] += 1;
                            if(player.fim[1] == 2)
                                cout << "██ O povo dessa dungeon devia aprender com você! Com um material desse, nenhum GOBLIN vai ousar chegar perto de você! Parabéns por ter saído são e salvo" << endl;
                        }else if((lastItem == loja[5] || lastItem == loja[6]) || lastItem == loja[7]){
                            player.fim[2] += 1;
                            if(player.fim[2] == 3)
                                cout << "██ Se você tava com tanta fome, por que não com… Ah, pera… Você comeu antes? Entendi. Você precisa se cuidar amigo..." << endl;
                        }else if(lastItem == loja[8] || lastItem == loja[9]){
                            player.fim[3] += 1;
                            if(player.fim[3] == 2)
                                cout << "██ Você veio comprar coisas pra arranjar uma pretendente?? Você sabe que tem lugares melhores pra isso né? Mas ok." << endl;
                        }else if(lastItem == loja[10]){
                            cout << "██ Ei… ei… EI! POR QUE VOCÊ NÃO ME DISSE QUE VOCÊ ERA O NEYMAR?? SABIA QUE IRIA TRAZER O HEXA! #VAIBRASILIAM" << endl;
                        }else if((lastItem == loja[11] || lastItem == loja[12]) || lastItem == loja[13]) {
                            player.fim[4] += 1;
                            if(player.fim[4] == 3)
                                cout << "██ MEUAMIGO, qual o preço do seu outfit?!" << endl;
                        }else if(lastItem == loja[14]){
                            cout << "██ Com esse ingresso eu só consigo dizer uma coisa… JÁ É JOGOS MERMÃO! XUPA CAASO!" << endl;
                        }
                    }
                    return 0;
                }
            }else{
                cout << "█ Andar (1) ou (2) casas?" << endl;
                cin >> opt;
                while (opt != '1' && opt != '2') {
                    cout << "█ Input inválido, escreva novamente..." << endl;
                    cin >> opt;
                }
                if (opt == '1') {
                    player.pos += 1;
                } else {
                    player.pos += 2;
                }
            }

            //Actions
            if(isGoblin(&player)){
                cout << endl << "Casa " << player.pos << ") " << "██ GOBLIN - Ei! Me passa seu ouro senão eu te destruo!" << endl;
                cout << "█ (A)CEITAR OU (B)ATALHAR? " << endl;
                cin >> opt;
                if((opt == 'A' || opt == 'a') && player.gold >= 20){
                    player.gold -= 20;
                    cout << "█ Você perdeu [20] de OURO e seu item [X], agora você tem [" << player.gold << "] de OURO..." << endl << endl;
                }else if((opt == 'A' || opt == 'a') && player.gold < 20) {
                    player.gold -= 20;
                    cout << "██ GOBLIN - HAHAHA! Você nem tem dinheiro! Vou até embora, não vou gastar meu tempo com você" << endl << endl;
                }else if(opt == 'B' || opt == 'b'){
                    player.luck = rand()%10;
                    if(player.luck % 3 == 0){
                        player.gold += 20;
                        cout << "█ Você DERROTOU o GOBLIN e ganhou [20] de OURO! Agora você tem [" << player.gold << "] de OURO..." << endl << endl;
                    }else{
                        player.gold -= 20;
                        while(!pilhaVazia(player.inv)) {
                            string lastItem = desempilha(player.inv);
                            player.luck = rand()%100;
                            if (lastItem == loja[3]) {
                                aux = 2;
                                cout << "██ GOBLIN - AI!!! Por que você carrega uma BARRA DE FERRO com você? Seu doente..."
                                     << endl;
                                break;
                            }else if(lastItem == loja[4] && player.luck % 3 == 0) {
                                aux = 1;
                                cout << "██ GOBLIN - Ve...neno... Ah... Aaaaaah..." << endl;
                                break;
                            }else if(lastItem == loja[4] && player.luck % 3 != 0){
                                aux = 0;
                                cout << "██ GOBLIN - Sério que você tentou me envenenar? Com isso aí? Rapaz... HAHAHA" << endl;
                                break;
                            }else
                                aux = 0;
                            cout << "█ Você perdeu o item \"" << lastItem << "\"!" << endl;
                        }
                        if(aux == 0) {
                            cout << "█ Você foi derrotado! O GOBLIN comeu seus itens e levou [20] de OURO... Agora você tem [" << player.gold << "] de OURO..." << endl << endl;
                        }else if(aux == 1){
                            cout << "█ Você matou o GOBLIN! Infelizmente o sistema digestivo deles é bem eficiente e seus itens não podem ser recuperados..." << endl << endl;
                        }else if(aux == 2){
                            cout << "█ O GOBLIN fugiu! Ainda bem que ele não comeu mais nenhum item seu né..." << endl << endl;
                        }
                    }
                }
            }else if(isChest(&player)){
                player.gold += 20;
                cout << "█ Casa " << player.pos << ") " << "Você encontrou um baú e ganhou [20] de OURO!" << endl << endl;

            }else{
                int value = rand()%15;
                cout << "█ Casa " << player.pos << ") " <<  "Você deseja comprar o item \"" << loja[value] << "\" por [10] de OURO? (S)im ou (N)ão?" << endl;
                cin >> opt;
                if(toupper(opt) == 'S'){
                    if(player.gold < 10){
                        cout << "█ Desculpe, mas você não tem ouro suficiente pra isso..." << endl << endl;
                    }else {
                        player.gold -= 10;
                        empilha(player.inv, value);
                        cout << "█ Obrigado pela sua aquisição" << endl;
                        cout << "█ Agora você tem [" << player.gold << "] de OURO" << endl << endl;
                    }
                }
            }
        }
    }else{
        cout << "█ Poxa... Talvez na próxima então... Tchau tchau!" << endl;
        return 0;
    }

}