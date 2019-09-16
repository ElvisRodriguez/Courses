const KILOGRAMS_PER_POUND = 0.453592;
const METERS_PER_INCH = 0.0254;

const feetBox = document.querySelector('#feet');
const inchesBox = document.querySelector('#inches');
const weightBox = document.querySelector('#weight');
const answerSpan = document.querySelector('#answer');
const considerationSpan = document.querySelector('#consideration');

weightBox.addEventListener('input', updateBMI);
feetBox.addEventListener('input', updateBMI);
inchesBox.addEventListener('input', updateBMI);

function bmiConsiderations(bmi) {
  if (bmi < 18.5) return 'underweight';
  if (bmi >= 18.5 && bmi < 25) return 'normal';
  if (bmi >= 25 && bmi < 30) return 'overweight';
  if (bmi >= 30) return 'obese';
}

function updateBMI() {
  const pounds = +weightBox.value;
  const feet = +feetBox.value;
  const inches = +inchesBox.value;
  const height = (feet * 12) + inches;
  const kilograms = pounds * KILOGRAMS_PER_POUND;
  const meters = height * METERS_PER_INCH;
  const bmi = kilograms / (meters * meters);
  answerSpan.textContent = bmi.toFixed(2);
  const bmi_consideration = bmiConsiderations(bmi);
  const message = `You are considered ${bmi_consideration}.`;
  considerationSpan.textContent = message;
}
