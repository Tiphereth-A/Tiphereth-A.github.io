let i = document.getElementById("about-header-image");
if (i)
  i.src =
    "/images/header/" +
    (() => {
      switch (new Date().getDate() % 2) {
        case 0:
          return "lab.nulla.top/ba-logo";
        case 1:
          return "science.nasa.gov/specials/your-name-in-landsat";
      }
    })() +
    "/1.webp";
