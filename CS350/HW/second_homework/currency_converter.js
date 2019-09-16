const inputBox = document.querySelector("#us_dollars");
const answerParagraph = document.querySelector("#answer");

function report() {
  const us_dollars = inputBox.value;
  const pesos = us_dollars * 19.74;

  if (isNaN(pesos)) {
    answerParagraph.textContent = '?';
  } else {
    answerParagraph.textContent = pesos.toFixed(2);
  }
}

inputBox.addEventListener('input', report);
