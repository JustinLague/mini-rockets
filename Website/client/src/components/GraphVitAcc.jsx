import { Grid } from '@mui/material';
import React, { useEffect } from 'react';
import { Api } from '../services/api.service';
import { Line } from 'react-chartjs-2';
import { Chart as ChartJS, CategoryScale, LinearScale, PointElement, LineElement, Title, Tooltip, Legend } from "chart.js";

ChartJS.register(
	CategoryScale,
	LinearScale,
	PointElement,
	LineElement,
	Title,
	Tooltip,
	Legend
  );

function GraphVitAcc() {
	const [vitesse, setVitesse] = React.useState([]);
	//const [acceleration, setAcceleration] = React.setState([]);


	useEffect(() => {
		var data = [];
		for(var i = 0; i < 10000; i++) {
			data.push(i*10);
		}

		setVitesse(data);

		Api().get("hello").then((data) => {
			console.log(data);
		})
	}, [])

	return (
		<React.Fragment>
			<Grid
				container
				spacing={0}
				direction="column"
				alignItems="center"
				justifyContent="center"
			>
				<Grid item xs={12}>
					<Line
						datasetIdKey='id'
						data={{
							labels: ['Jun', 'Jul', 'Aug'],
							datasets: [
							{
								id: 1,
								label: '',
								data: vitesse,
							},
							{
								id: 2,
								label: '',
								data: [3, 2, 1],
							},
							],
						}}
					/>
				</Grid>
			</Grid>
		</React.Fragment>
	);
}

export default GraphVitAcc;
