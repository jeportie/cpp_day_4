// Quiz functionality
let score = 0;
const totalQuestions = 12;
const answeredQuestions = new Set();

function showAnswer(id) {
    const answer = document.getElementById(id);
    if (answer.style.display === "block") {
        answer.style.display = "none";
    } else {
        answer.style.display = "block";
    }
}

function checkAnswer(questionNumber, selectedOption, correctOption) {
    const options = document.getElementsByName(`q${questionNumber}`);
    const selectedLabel = document.querySelector(`label[for="${selectedOption}"]`);
    
    // Reset all options
    options.forEach(option => {
        const label = document.querySelector(`label[for="${option.id}"]`);
        label.parentElement.classList.remove('correct-answer', 'wrong-answer');
    });
    
    if (selectedOption === correctOption) {
        selectedLabel.parentElement.classList.add('correct-answer');
        if (!answeredQuestions.has(questionNumber)) {
            score++;
            answeredQuestions.add(questionNumber);
            updateProgress();
        }
    } else {
        selectedLabel.parentElement.classList.add('wrong-answer');
        document.querySelector(`label[for="${correctOption}"]`).parentElement.classList.add('correct-answer');
    }
    
    document.getElementById(`answer${questionNumber}`).style.display = "block";
}

function updateProgress() {
    const progressPercentage = (answeredQuestions.size / totalQuestions) * 100;
    document.getElementById('progressBar').style.width = `${progressPercentage}%`;
    document.getElementById('scoreDisplay').textContent = `Score: ${score}/${totalQuestions}`;
}

// Tab functionality
function openTab(tabId) {
    // Hide all tab contents
    const tabContents = document.getElementsByClassName('tab-content');
    for (let i = 0; i < tabContents.length; i++) {
        tabContents[i].classList.remove('active');
    }
    
    // Deactivate all tab buttons
    const tabButtons = document.getElementsByClassName('tab-button');
    for (let i = 0; i < tabButtons.length; i++) {
        tabButtons[i].classList.remove('active');
    }
    
    // Show the selected tab content and activate the button
    document.getElementById(tabId).classList.add('active');
    event.currentTarget.classList.add('active');
}

// Initialize ag-Charts
document.addEventListener('DOMContentLoaded', function() {
    // Create memory usage comparison chart
    if (typeof agCharts !== 'undefined') {
        const options = {
            container: document.getElementById('memoryChart'),
            title: {
                text: 'Memory Usage Comparison'
            },
            data: [
                { type: 'Shallow Copy', memory: 100, objects: 2 },
                { type: 'Deep Copy', memory: 150, objects: 2 },
                { type: 'Virtual Functions', memory: 120, objects: 2 },
                { type: 'Non-Virtual Functions', memory: 100, objects: 2 }
            ],
            series: [{
                xKey: 'type',
                yKey: 'memory',
                yName: 'Memory Usage (bytes)'
            }]
        };
        
        agCharts.AgChart.create(options);
    }
});

