void analyze_neutron_data() {

    TFile *file = TFile::Open("my_geant4_projects/geant4-neutron-sim6/build/neutron_output.root");


    if (!file || file->IsZombie()) {
        std::cerr << "Hata: 'neutron_output.root' dosyası açılamadı veya bozuk. Yolu kontrol edin." << std::endl;
        return;
    }


    TH1D *hNeutronEnergy = (TH1D*)file->Get("NeutronEnergy");
    TH1D *hNeutronAngle = (TH1D*)file->Get("NeutronAngle");

    if (!hNeutronEnergy || !hNeutronAngle) {
        std::cerr << "Hata: Histogramlar bulunamadı. İsimlerini (NeutronEnergy, NeutronAngle) kontrol edin." << std::endl;
        file->Close();
        return;
    }

    std::cout << "\n--- Nötron Analiz Sonuçları ---" << std::endl;
    std::cout << "NeutronEnergy Min: " << hNeutronEnergy->GetXaxis()->GetXmin() << std::endl;
    std::cout << "NeutronEnergy Max: " << hNeutronEnergy->GetXaxis()->GetXmax() << std::endl;
    std::cout << "NeutronEnergy Ortalama: " << hNeutronEnergy->GetMean() << " MeV" << std::endl;
    std::cout << "NeutronEnergy StdDev: " << hNeutronEnergy->GetStdDev() << " MeV" << std::endl;
    std::cout << "Toplam Kaçan Nötron Sayısı (Enerji Histogramından): " << hNeutronEnergy->GetEntries() << std::endl;

    std::cout << "\nNeutronAngle Min: " << hNeutronAngle->GetXaxis()->GetXmin() << std::endl;
    std::cout << "NeutronAngle Max: " << hNeutronAngle->GetXaxis()->GetXmax() << std::endl;
    std::cout << "Ortalama Nötron Açısı: " << hNeutronAngle->GetMean() << " Derece" << std::endl; // Birimini teyit et!
    std::cout << "Nötron Açı Standart Sapması: " << hNeutronAngle->GetStdDev() << " Derece" << std::endl; // Birimini teyit et!
    std::cout << "-------------------------------" << std::endl;

    TCanvas *c1 = new TCanvas("c1", "Nötron Enerji ve Açı Dağılımı", 1200, 600); // Kanvas boyutu
    c1->Divide(2,1); // Kanvası 2 panele ayır (sol ve sağ)

    c1->cd(1);
    // Enerji histogramı için eksen ayarları ve çizim
    // Kendi verilerinin yoğunlaştığı aralığa göre Min ve Max değerlerini buradan ayarlayabilirsin.
    hNeutronEnergy->GetXaxis()->SetRangeUser(0, 5); // Örnek: 0'dan 5 MeV'e kadar göster
    hNeutronEnergy->SetXTitle("Enerji (MeV)");
    hNeutronEnergy->SetYTitle("Olay Sayısı");
    hNeutronEnergy->Draw();

    c1->cd(2); // Sağ panele geç
    // Açı histogramı için eksen ayarları ve çizim
    // Kendi verilerine göre Min ve Max değerlerini buradan ayarlayabilirsin.
    hNeutronAngle->GetXaxis()->SetRangeUser(0, 180); // Örnek: 0'dan 180 Dereceye kadar göster
    hNeutronAngle->SetXTitle("Açı (Derece)"); // Birimini teyit et
    hNeutronAngle->SetYTitle("Olay Sayısı");
    hNeutronAngle->Draw();

    // --- 5. Grafikleri Kaydet (İsteğe Bağlı) ---
    c1->SaveAs("neutron_analysis_plot.png"); // Mevcut dizine PNG olarak kaydet


    // --- 6. Kaynakları Temizle ---
    file->Close();
    delete c1; // Kanvas objesini sil
    // Not: hNeutronEnergy ve hNeutronAngle objeleri dosya kapanınca silineceği için burada tekrar delete etmeye gerek yok.
}