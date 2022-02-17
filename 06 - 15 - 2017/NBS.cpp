/// Sub 1 : sinh tất cả -> ktra -> đếm
/// Sub 2 : QHĐ từ 1 đến i có bao nhiêu bit 1
/// Sub 3 : Số bit 1 là chẵn hay lẻ. => suy ra số bit 0 chẵn hay lẻ
/// Sub 6 : Nếu n lẻ : Mọi xâu đều thỏa mãn -> Chuyển từ nhị phân sang thập phân (nó chính là số thứ tự)
///         Nếu n chẵn : Loại đi TH cả 2 số bit đều lẻ. => Bỏ bit cuối và làm vs n-1 lẻ
