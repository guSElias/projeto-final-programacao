#include <iostream>
#include "Clube.h"
#include <vector>

#include "Atleta.h"

using namespace std;
void testarClube()
{

    cout << "======================================\n";
    cout << "          INÍCIO DOS TESTES\n";
    cout << "======================================\n";

    // 1. Criação de Clubes
    Clube realMadrid("Real Madrid", 1902);
    Clube flamengo("Flamengo", 1895);

    cout << "\n>>> Clubes Criados:\n";
    cout << "- " << realMadrid.getNome() << " (Fundado em " << 1902 << ")\n";
    cout << "- " << flamengo.getNome() << " (Fundado em " << 1895 << ")\n";

    // ---

    // 2. Criação de Atletas Reais
    Atleta viniciusJr("Vinícius Jr.", 7, {"PE", "ATA"});
    Atleta rodrygo("Rodrygo", 11, {"PE", "PD", "ATA", "MEI"});
    Atleta gabigol("Gabriel Barbosa", 10, {"ATA"});
    Atleta brunoHenrique("Bruno Henrique", 27, {"PE", "ATA"});

    // ---

    // 3. Comprando Atletas (Real Madrid)
    cout << "\n>>> " << realMadrid.getNome() << " - Comprando Atletas\n";
    realMadrid.comprarAtleta(viniciusJr);
    cout << "* " << viniciusJr.getNome() << " comprado.\n";
    realMadrid.comprarAtleta(rodrygo);
    cout << "* " << rodrygo.getNome() << " comprado.\n";

    // 4. Comprando Atletas (Flamengo)
    cout << "\n>>> " << flamengo.getNome() << " - Comprando Atletas\n";
    flamengo.comprarAtleta(gabigol);
    cout << "* " << gabigol.getNome() << " comprado.\n";
    flamengo.comprarAtleta(brunoHenrique);
    cout << "* " << brunoHenrique.getNome() << " comprado.\n";

    // ---

    // 5. Exibindo Elencos Iniciais
    realMadrid.exibirElenco();
    flamengo.exibirElenco();

    // ---

    // 6. Vendendo Atleta (Exemplo: Real Madrid vende Rodrygo)
    cout << "\n>>> " << realMadrid.getNome() << " - Vendendo Atleta\n";
    realMadrid.venderAtleta(rodrygo);
    cout << "* " << rodrygo.getNome() << " vendido.\n";

    // 7. Exibindo Elenco Após Venda
    realMadrid.exibirElenco();
}

int main() {
    testarClube();
}