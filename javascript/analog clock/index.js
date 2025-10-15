function updateClock() {
  const now = new Date();

  const seconds = now.getSeconds();
  const minutes = now.getMinutes();
  const hours = now.getHours();

  // Degrees for rotation
  const secondsDeg = seconds * 6; // 360 / 60
  const minutesDeg = (minutes * 6) + (seconds * 0.1); // smooth movement
  const hoursDeg = (hours % 12) * 30 + (minutes * 0.5); // smooth movement

  // Select hands
  document.querySelector(".second-hand").style.transform = `rotate(${secondsDeg}deg)`;
  document.querySelector(".minute-hand").style.transform = `rotate(${minutesDeg}deg)`;
  document.querySelector(".hour-hand").style.transform = `rotate(${hoursDeg}deg)`;
}

// Run every second
setInterval(updateClock, 1000);
updateClock();
