// Fungsi untuk mengecek apakah elemen terlihat saat di-scroll
function isElementInViewport(el) {
  const rect = el.getBoundingClientRect();
  return (
    rect.top >= 0 &&
    rect.left >= 0 &&
    rect.bottom <= (window.innerHeight || document.documentElement.clientHeight) &&
    rect.right <= (window.innerWidth || document.documentElement.clientWidth)
  );
}

// Fungsi untuk menambahkan kelas 'fade-in' pada elemen yang terlihat
function handleScrollAnimation() {
  const elements = document.querySelectorAll('*');
  elements.forEach(element => {
    if (isElementInViewport(element)) {
      element.classList.add('fade-in');
    }
  });
}

// Menambahkan event listener untuk scroll
window.addEventListener('scroll', handleScrollAnimation);

// Panggil fungsi saat halaman dimuat untuk mengecek elemen yang sudah terlihat
window.addEventListener('load', handleScrollAnimation);